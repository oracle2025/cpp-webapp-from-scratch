#pragma once
#include <string>

enum class Method { GET, POST, METHOD_NOT_ALLOWED };

struct RouteId
{
    RouteId(const Method& method, std::string path);
    explicit RouteId(std::string path);
    bool operator<(const RouteId& rhs) const;

    RouteId(const RouteId&) = default;
    RouteId& operator=(const RouteId&) = delete;

private:
    Method method = Method::GET;
    std::string path;
};
