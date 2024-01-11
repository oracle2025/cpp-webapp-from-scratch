#include "Router.hpp"

#include <map>
#include <string>
#include <Poco/URI.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

#include "RouteId.hpp"

struct Router::Impl
{
    std::map<RouteId, handler_type> routes;
};

void Router::add(const std::string& path, handler_type handler)
{
    impl->routes[RouteId(path)] = std::move(handler);
}

Router::Router()
    : impl(new Impl)
{
}

Router::~Router()
{
    delete impl;
    impl = nullptr;
}

void Router::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
    using Poco::URI;
    const auto path = URI(request.getURI()).getPath();

    auto it = impl->routes.find(RouteId(path));
    if (it == impl->routes.end())
    {
        response.setStatus(Poco::Net::HTTPResponse::HTTP_NOT_FOUND);
        response.send();
        return;
    }
    it->second(request, response);
}
