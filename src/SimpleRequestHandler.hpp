#pragma once

namespace Poco
{
    namespace Net
    {
        class HTTPServerRequest;
        class HTTPServerResponse;
    }
}

struct Router;

struct SimpleRequestHandler
{
    using HTTPServerRequest = Poco::Net::HTTPServerRequest;
    using HTTPServerResponse = Poco::Net::HTTPServerResponse;
    void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response);
    explicit SimpleRequestHandler(Router& router);
    ~SimpleRequestHandler();
    SimpleRequestHandler(const SimpleRequestHandler&) = delete;
    SimpleRequestHandler& operator=(const SimpleRequestHandler&) = delete;

private:
    struct Impl;
    Impl* impl;
};
