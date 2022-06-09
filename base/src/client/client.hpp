#pragma once
#ifndef clientOsInit
#include "common.hpp"
#define clientOsInit
#endif

typedef websocketpp::config::asio_client::message_type::ptr message_ptr;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;


namespace discordOs {
    namespace clientOs {
    
#define clientpp websocketpp::client<websocketpp::config::asio_tls_client>
        
        class discordOs {
            void on_message(clientpp* c, websocketpp::connection_hdl hdl);
            void on_close(clientpp* c, websocketpp::connection_hdl hdl);
            void on_open(clientpp* c, websocketpp::connection_hdl hdl);

            void (*on_invalid)(events_os ev);
            void (*on_msg)(client::message msg);
            void (*on_login)(client client);

            //void on_fail(clientpp* c, websocketpp::connection_hdl hdl, discord* _disc);
            std::error_code ec;
            clientpp c;
        public:
            const char* token;
            bool bot = true;

            bool initialised;
            bool connected = true;
            bool ConClose;
            bool retry;
            bool paused = false;

            //void pause_client();
            //void resume_client();

            void on_close(clientpp* c, websocketpp::connection_hdl hdl);

            bool get_user(std::string id);

            discordOs(const char* token, bool bot, );
            discordOs(const char* token, bool bot);
            discordOs() {};
            ~discord() {};
            std::thread thread_client;
            socket_msg socket_msg;
            fetched_user fetched_user;
            embed emb;
            client cli;

        };
    }
}