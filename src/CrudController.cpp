#include "CrudController.hpp"

struct CrudController::Impl
{
};

CrudController::CrudController(Router& router)
    : impl(new Impl)
{
	//router.get("/", [](){});
}
CrudController::~CrudController()
{
    delete impl;
    impl = nullptr;
}
		

