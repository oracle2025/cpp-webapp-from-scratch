#include <cstdlib>
#include <iostream>
#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPRequestHandler.h>

#include "CrudController.hpp"
#include "SimpleRequestHandler.hpp"
#include "Router.hpp"

using std::vector;
using std::string;

using Poco::Net::HTTPRequestHandler;

struct RequestHandler : public HTTPRequestHandler
{
    using HTTPServerRequest = Poco::Net::HTTPServerRequest;
    using HTTPServerResponse = Poco::Net::HTTPServerResponse;

    explicit RequestHandler(Router& router): handler(router)
    {
    }

    void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response) override
    {
        handler.handleRequest(request, response);
    }

    SimpleRequestHandler handler;
};

using Poco::Net::HTTPRequestHandlerFactory;

struct HandlerFactory : public HTTPRequestHandlerFactory
{
    using HTTPRequestHandler = Poco::Net::HTTPRequestHandler;
    using HTTPServerRequest = Poco::Net::HTTPServerRequest;

    explicit HandlerFactory(Router& router): router(router)
    {
    }

    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request) override
    {
        std::cout << "Request: " << request.getURI() << "\n";
        return new RequestHandler(router);
    }

private:
    Router& router;
};


using Poco::Util::ServerApplication;

struct App : public ServerApplication
{
    int main(const vector<string>& args) override
    {
        using namespace Poco::Net;
        ServerSocket socket(SocketAddress("localhost", 8080));
        Router router;
        CrudController crud(router);
        HTTPServer server(new HandlerFactory(router), socket, new HTTPServerParams);
        server.start();
        waitForTerminationRequest();
        server.stop();
        return EXIT_OK;
    }
};

int main(int argc, char** argv)
{
    try
    {
        App app;
        return app.run(argc, argv);
    }
    catch (...)
    {
        std::cout << "Exception!\n";
        return EXIT_FAILURE;
    }
}
