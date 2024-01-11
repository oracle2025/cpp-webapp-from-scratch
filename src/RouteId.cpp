#include "RouteId.hpp"
#include <string>

RouteId::RouteId(const Method& method, std::string path)
    : method(method), path(std::move(path))
{
}

RouteId::RouteId(std::string path)
    :
    path(std::move(path))
{
}


bool RouteId::operator<(const RouteId& rhs) const
{
    if (method != rhs.method)
    {
        return method < rhs.method;
    }
    return path < rhs.path;
}
