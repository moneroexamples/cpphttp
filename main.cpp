#include "drogon/drogon.h"

#include "src/controllers/InfoCtrl.h"

#include <iostream>

using namespace myapp;

using namespace drogon;
using namespace std::literals::chrono_literals;


int
main(int argc, const char *argv[])
{
    // create regular http controller. It will provide
    auto info_ctrl = make_shared<InfoCtrl>(InfoCtrl());
    app().registerController(info_ctrl);

    LOG_INFO << "InfoCtrl registered";

    auto port = 8080u;

    LOG_INFO << "Listening at 127.0.0.1:" << port;

    app().setThreadNum(1);
    app().setIdleConnectionTimeout(1h);

    app().addListener("0.0.0.0", port);

    app().run();

    return EXIT_SUCCESS;
}
