#include "Router.hpp"

#include <map>
#include <string>

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
