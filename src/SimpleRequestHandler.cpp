#include "SimpleRequestHandler.hpp"

#include <iostream>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include "IndexTemplate.hpp"

struct SimpleRequestHandler::Impl
{
};

void SimpleRequestHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
    std::cout << "Handle Request: " << request.getURI() << "\n";
    response.setChunkedTransferEncoding(true);
    response.setContentType("text/html");
    IndexTemplate indexTemplate;
    indexTemplate.setTitle("Hello");
    indexTemplate.setContent("World");
    indexTemplate.render(response.send());
}

SimpleRequestHandler::SimpleRequestHandler():
    impl(new Impl)
{
}

SimpleRequestHandler::~SimpleRequestHandler()
{
    delete impl;
    impl = nullptr;
}
