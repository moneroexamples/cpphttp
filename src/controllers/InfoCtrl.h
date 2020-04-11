#pragma once


#include "drogon/HttpController.h"

#include "nlohmann/json.hpp"

namespace myapp
{

using namespace drogon;
using namespace std;

namespace nl = nlohmann;


class SearchTaskManager;

class InfoCtrl: public HttpController<InfoCtrl, false>
{
public:

	METHOD_LIST_BEGIN
	ADD_METHOD_TO(InfoCtrl::status, "/", Get);
	METHOD_LIST_END
	
    InfoCtrl() = default;

	InfoCtrl(string message): _message {message} 
    {};

	virtual void
	status(HttpRequestPtr const& req,
		std::function<void (const HttpResponsePtr &)>&& 
			callback);
	
protected:

    string _message; 

    virtual void 
    make_json_response(nl::json&& out_data,
       std::function<void (const HttpResponsePtr &)>&& 
           callback);
};


}


