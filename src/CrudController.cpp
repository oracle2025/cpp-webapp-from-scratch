#include "CrudController.hpp"
#include "Router.hpp"
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

struct CrudController::Impl
{
};

CrudController::CrudController(Router& router)
    : impl(new Impl)
{
    using HTTPServerRequest = Poco::Net::HTTPServerRequest;
    using HTTPServerResponse = Poco::Net::HTTPServerResponse;
    router.add("/", [](HTTPServerRequest& request, HTTPServerResponse& response)
    {
        //record().list();
        /*
         * CrudRowTemplate rowTemplate;
         * std::ostringstream rows;
         * for (const auto& record : records) {
         *    rowTemplate.setRecord(record);
         *    rowTemplate.render(rows);
         * }
         * CrudListTemplate listTemplate;
         * listTemplate.setRows(rows.str());
         * IndexTemplate indexTemplate;
         * indexTemplate.setTitle("List");
         * indexTemplate.setContent(listTemplate.render());
         * indexTemplate.render(response.send());
         */
        response.setChunkedTransferEncoding(true);
        response.setContentType("text/html");
        response.send() << R"(Crud Index)";
    });
    router.add("/new", [](HTTPServerRequest& request, HTTPServerResponse& response)
    {
        //CrudNewTemplate
        response.setChunkedTransferEncoding(true);
        response.setContentType("text/html");
        response.send() << R"(Crud Index)";
    });
    router.add("/create", [](HTTPServerRequest& request, HTTPServerResponse& response)
    {
        //record.insert();
    });
    router.add("/edit", [](HTTPServerRequest& request, HTTPServerResponse& response)
    {
        //record().pop();
        //CrudEditTemplate
    });
    router.add("/update", [](HTTPServerRequest& request, HTTPServerResponse& response)
    {
        //record().pop();
        //record().update();
    });
    router.add("/delete", [](HTTPServerRequest& request, HTTPServerResponse& response)
    {
        //record().pop();
        //record.erase();
    });
}

CrudController::~CrudController()
{
    delete impl;
    impl = nullptr;
}
