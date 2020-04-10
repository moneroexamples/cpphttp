#include "InfoCtrl.h"


namespace myapp
{

void
InfoCtrl::status(HttpRequestPtr const& req,
   std::function<void (const HttpResponsePtr &)>&& callback)
{

    nl::json jstatus {{"status", "Hello world from "}};

    make_json_response(std::move(jstatus), 
                       std::move(callback));
}


void 
InfoCtrl::make_json_response(nl::json&& out_data,
   std::function<void (const HttpResponsePtr &)>&& 
       callback)
{
    auto resp = HttpResponse::newHttpResponse();
    resp->setStatusCode(k200OK);
    resp->setContentTypeCode(ContentType::CT_APPLICATION_JSON);
    resp->addHeader("Access-Control-Allow-Origin", "*");
    resp->setBody(out_data.dump());

    callback(resp);
}

}
