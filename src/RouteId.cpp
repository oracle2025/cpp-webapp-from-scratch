#include "RouteId.hpp"
#include <string>

struct RouteId::Impl
{
    Method method = Method::GET;
    std::string path;
};

RouteId::RouteId(const Method& method, std::string path)
    :
    impl(new Impl)
{
    impl->method = method;
    impl->path = std::move(path);
}

RouteId::RouteId(std::string path)
    :
    impl(new Impl)
{
    impl->path = std::move(path);
}

RouteId::~RouteId()
{
    delete impl;
    impl = nullptr;
}


bool RouteId::operator<(const RouteId& rhs) const
{
    if (impl->method != rhs.impl->method)
    {
        return impl->method < rhs.impl->method;
    }
    return impl->path < rhs.impl->path;
}
