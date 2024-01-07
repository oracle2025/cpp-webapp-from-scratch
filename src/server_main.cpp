#include <cstdlib>
#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPRequestHandler.h>

using std::vector;
using std::string;

using Poco::Net::HTTPRequestHandler;
struct RequestHandler : public HTTPRequestHandler {
	using HTTPServerRequest = Poco::Net::HTTPServerRequest;
	using HTTPServerResponse = Poco::Net::HTTPServerResponse;
	void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response) override
	{
		std::cout << "Handle Request: " << request.getURI() << "\n";
		response.setChunkedTransferEncoding(true);
		response.setContentType("text/html");
		response.send() << "<h1>Hello World</h1>\n";
	}
};

using Poco::Net::HTTPRequestHandlerFactory;
struct HandlerFactory : public HTTPRequestHandlerFactory {
	using HTTPRequestHandler = Poco::Net::HTTPRequestHandler;
	using HTTPServerRequest = Poco::Net::HTTPServerRequest;
	HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request) override
	{
		std::cout << "Request: " << request.getURI() << "\n";
		return new RequestHandler;
	}
};

using Poco::Net::HTTPServer;
struct WebServer {
	void start()
	{
		std::cout << "Starting ...\n";
		using namespace Poco::Net;
		ServerSocket socket(SocketAddress(Poco::Net::IPAddress("127.0.0.1"), 8080));
		auto params = new HTTPServerParams;
		params->setServerName("localhost:8080");
		server = std::make_shared<HTTPServer>(new HandlerFactory, socket, params);
	}
	void stop()
	{
	}
	std::shared_ptr<HTTPServer> server;
};

using Poco::Util::ServerApplication;
struct App : public ServerApplication {
	int main(const vector<string>& args) override
	{
		WebServer server;
		server.start();
		waitForTerminationRequest();
		server.stop();
		return EXIT_OK;
	}
};

int main(int argc, char**argv)
{
	try {
		App app;
		return app.run(argc, argv);
	} catch (...) {
		std::cout << "Exception!\n";
		return EXIT_FAILURE;
	}
}
