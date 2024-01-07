#pragma once

#include <ostream>

struct IndexTemplate
{
    IndexTemplate();
    ~IndexTemplate();

    void setTitle(const char* title);
    void setContent(const char* content);
    void render(std::ostream& out);

private:
    struct Impl;
    Impl* impl;
};
