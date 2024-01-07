#include "SimpleRequestHandler.hpp"

#include <iostream>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

struct SimpleRequestHandler::Impl
{
};

void SimpleRequestHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
    std::cout << "Handle Request: " << request.getURI() << "\n";
    response.setChunkedTransferEncoding(true);
    response.setContentType("text/html");
    response.send() << "<h1>Hello World</h1>\n";
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
