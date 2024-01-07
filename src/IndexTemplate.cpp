#include "IndexTemplate.hpp"
#include <string>
#include <ostream>

struct IndexTemplate::Impl
{
    std::string title;
    std::string content;
};

IndexTemplate::IndexTemplate()
    : impl(new Impl)
{
}

IndexTemplate::~IndexTemplate()
{
    delete impl;
    impl = nullptr;
}

void IndexTemplate::setTitle(const char* title)
{
    impl->title = title;
}

void IndexTemplate::setContent(const char* content)
{
    impl->content = content;
}

void IndexTemplate::render(std::ostream& out)
{
    out << "<h1>" << impl->title << "</h1>\n";
    out << "<p>" << impl->content << "</p>\n";
}
