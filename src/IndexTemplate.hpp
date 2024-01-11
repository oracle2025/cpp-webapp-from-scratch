#pragma once

#include <iosfwd>

struct IndexTemplate
{
    IndexTemplate();
    ~IndexTemplate();

    void setTitle(const char* title);
    void setContent(const char* content);
    void render(std::ostream& out);
    IndexTemplate(const IndexTemplate&) = delete;
    IndexTemplate& operator=(const IndexTemplate&) = delete;

private:
    struct Impl;
    Impl* impl;
};
