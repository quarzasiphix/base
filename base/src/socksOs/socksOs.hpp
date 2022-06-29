#pragma once
#include "common.hpp"

#define clientpp websocketpp::client<websocketpp::config::asio_tls_client>

struct socksOs
{
    websocketpp::connection_hdl hdl;
    std::error_code ec;
    std::thread th;
    clientpp* c;
    bool running;
    int runCode;

    void heartbeat(nlohmann::json hb);
	bool sendMsg(const char* msg);
};

