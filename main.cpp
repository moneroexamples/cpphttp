#include "drogon/drogon.h"

#include "src/controllers/InfoCtrl.h"

#include <iostream>
#include <unistd.h>

using namespace myapp;
using namespace std;
using namespace drogon;


namespace {

void
show_usage(string name) 
{
    std::cerr << "Usage: " << name << " <option(s)> SOURCES"
              << "Options:\n"
              << "\t-h,--help\tShow this help message\n"
              << "\t-n,--name HOSTNAME\tSpecify hostname"
              << std::endl;
}

string
get_hostname() 
{
    char hostname[256];
    gethostname(hostname, 256);
    return hostname;
}


}


int
main(int argc, const char *argv[])
{
    
    string hostname = get_hostname();

    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            string arg = argv[i];

            if ((arg == "-h") || (arg == "--help")) 
            {
                show_usage(argv[0]);
                return EXIT_SUCCESS;
            }
            else if ((arg == "-n") || (arg == "--name")) 
            {
                if (i + 1 < argc) 
                {
                    // overwrite hostname 
                    hostname = argv[++i];
                }
                else
                {
                    cerr << "--destination option requires one argument!" << endl;
                    return EXIT_FAILURE;
                }
            }
        }
    }

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
