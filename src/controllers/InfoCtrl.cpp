#include "InfoCtrl.h"

#include <stdlib.h>

namespace myapp
{

void
InfoCtrl::status(HttpRequestPtr const& req,
   std::function<void (const HttpResponsePtr &)>&& callback)
{


    string msg_to_return = _message;


    if (_random)
    {
        srand(time(NULL));

        msg_to_return = rand() % 2 
                        ? "wrong msg"s 
                        : msg_to_return;
    }

    nl::json jstatus {
        {"message", msg_to_return}
    };

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
