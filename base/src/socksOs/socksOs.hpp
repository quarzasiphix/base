#pragma once
#include <websocketpp/config/asio_client.hpp>
#include <websocketpp/client.hpp>
#include <websocketpp/transport/asio/security/tls.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/function.hpp>

#define CPPHTTPLIB_OPENSSL_SUPPORT

#include <httplib.h>
#define _WINSOCK2API_
#define _WINSOCKAPI_   /* Prevent inclusion of winsock.h in windows.h */

#pragma comment(lib, "libboost_date_time-vc142-mt-s-x64-1_79.lib")
#pragma comment(lib, "libboost_random-vc142-mt-s-x64-1_79.lib")
#pragma comment(lib, "libs/libcurl_a.lib")
#pragma comment(lib, "libs/libssl.lib")

typedef websocketpp::config::asio_client::message_type::ptr message_ptr;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

#include "common.hpp"

#define clientpp websocketpp::client<websocketpp::config::asio_tls_client>

class socksOs
{
    struct on {
        void (*message)(socksOs& sock);
        void (*close)(socksOs& sock);
        void (*open)(socksOs& sock);
    };

    websocketpp::connection_hdl hdl;
    clientpp* c;
    std::thread th;
public:
    std::error_code ec;
    bool running{};
    int runCode = 0;

    socksOs();

    on events;
    void heartbeat(nlohmann::json hb);
	bool sendMsg(const char* msg);
};

