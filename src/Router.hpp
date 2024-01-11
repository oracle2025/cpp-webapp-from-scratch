#pragma once
#include <functional>
#include <iosfwd>

namespace Poco
{
    namespace Net
    {
        class HTTPServerRequest;
        class HTTPServerResponse;
    }
}

struct Router
{
    using HTTPServerRequest = Poco::Net::HTTPServerRequest;
    using HTTPServerResponse = Poco::Net::HTTPServerResponse;
    using handler_type = std::function<void(HTTPServerRequest& request, HTTPServerResponse& response)>;

    void add(const std::string& path, handler_type handler);
    Router();
    ~Router();
    Router(const Router&) = delete;
    Router& operator=(const Router&) = delete;

    void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response);

private:
    struct Impl;
    Impl* impl;
};
