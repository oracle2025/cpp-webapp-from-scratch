#pragma once

struct Router;

struct CrudController
{
    explicit CrudController(Router& router);
    ~CrudController();
    CrudController(const CrudController&) = delete;
    CrudController& operator=(const CrudController&) = delete;

private:
    struct Impl;
    Impl* impl;
};
