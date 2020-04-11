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
              << "\t-n,--name HOSTNAME\tSpecify hostname\n"
              << "\t-m,--message MESSAGE\tSpecify message"
              << std::endl;
}

string
get_hostname() 
{
    char hostname[256];
    gethostname(hostname, 256);
    return hostname;
}

map<string, string>
parse_argv(int argc, const char *argv[])
{
    map<string, string> arguments;

    arguments["hostname"] = get_hostname();

    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            string arg = argv[i];

            if ((arg == "-h") || (arg == "--help")) 
            {
                show_usage(argv[0]);
                arguments["help"]="true";
                return arguments;
            }
            else if ((arg == "-n") || (arg == "--name")) 
            {
                if (i + 1 < argc) 
                {
                    // overwrite hostname 
                    arguments["hostname"] = argv[++i];
                }
                else
                {
                    cerr << "--name option requires one argument!" << endl;
                    arguments["error"] = "true";
                    return arguments;
                }
            }
            else if ((arg == "-m") || (arg == "--message")) 
            {
                if (i + 1 < argc) 
                {
                    // overwrite hostname 
                    arguments["message"] = argv[++i];
                }
                else
                {
                    cerr << "--message option requires one argument!" << endl;
                    arguments["error"] = "true";
                    return arguments;
                }
            }
        }
    }


    if (arguments.count("message") == 0) 
    {
        arguments["message"] = "Hello world from " 
                    + arguments["hostname"];
    }

    return arguments;
}


}


int
main(int argc, const char *argv[])
{

    auto args = parse_argv(argc, argv);

    if (args.count("error"))
        return EXIT_FAILURE;
    
    if (args.count("help"))
        return EXIT_SUCCESS;
        
    auto info_ctrl = make_shared<InfoCtrl>(
            InfoCtrl(args["message"]));

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
