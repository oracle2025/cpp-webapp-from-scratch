#pragma once

struct Router;

struct CrudController {
	CrudController(Router& router);
	~CrudController();
private:
    struct Impl;
    Impl* impl;
};
