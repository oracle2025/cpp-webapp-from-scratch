#pragma once
#include <iosfwd>

enum class Method { GET, POST, METHOD_NOT_ALLOWED };

struct RouteId
{
    RouteId(const Method& method, std::string path);
    explicit RouteId(std::string path);
    ~RouteId();
    bool operator<(const RouteId& rhs) const;

private:
    struct Impl;
    Impl* impl;
};
