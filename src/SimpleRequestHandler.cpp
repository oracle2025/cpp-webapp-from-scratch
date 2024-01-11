#include "SimpleRequestHandler.hpp"

#include <iostream>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/URI.h>
#include "IndexTemplate.hpp"
#include "Router.hpp"

struct SimpleRequestHandler::Impl
{
    Impl(Router& router): router(router)
    {
    }

    Router& router;
};

void SimpleRequestHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
    using Poco::URI;
    std::cout << "Handle Request: " << request.getURI() << "\n";

    const auto valid_paths = {"/", "/new", "/create", "/edit", "/update", "/delete"};
    const auto path = URI(request.getURI()).getPath();

    for (const auto& route : valid_paths)
    {
        continue;
        if (path == route)
        {
            response.setChunkedTransferEncoding(true);
            response.setContentType("text/html");
            IndexTemplate indexTemplate;
            indexTemplate.setTitle(path.c_str());
            indexTemplate.setContent(R"(
<ul>
	<li><a href="/">Home</a></li>
	<li><a href="/new">New</a></li>
	<li><a href="/create">Create</a></li>
	<li><a href="/edit">Edit</a></li>
	<li><a href="/update">Update</a></li>
	<li><a href="/delete">Delete</a></li>
</ul>
)");
            indexTemplate.render(response.send());

            return;
        }
    }
    impl->router.handleRequest(request, response);
}

SimpleRequestHandler::SimpleRequestHandler(Router& router):
    impl(new Impl(router))
{
}

SimpleRequestHandler::~SimpleRequestHandler()
{
    delete impl;
    impl = nullptr;
}
