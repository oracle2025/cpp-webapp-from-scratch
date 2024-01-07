#pragma once

namespace Poco
{
    namespace Net
    {
        class HTTPServerRequest;
        class HTTPServerResponse;
    }
}

struct SimpleRequestHandler
{
    using HTTPServerRequest = Poco::Net::HTTPServerRequest;
    using HTTPServerResponse = Poco::Net::HTTPServerResponse;
    void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response);
    SimpleRequestHandler();
    ~SimpleRequestHandler();

private:
    struct Impl;
    Impl* impl;
};
