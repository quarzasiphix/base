#include "common.hpp"
#include "clientsOs/clientsOs.hpp"

namespace discordsOs {
    class discordOs {

    };

    namespace clientsOs {
        class clientOs {
            bool bot{};
            bool running{};
        };
    }
}
    /*
        class discordOs {


        void (*on_invalid)();//events_os ev);
        void (*on_msg)();//client::message msg);
        void (*on_login)();//client client);

        //void on_fail(clientpp* c, websocketpp::connection_hdl hdl, discord* _disc);


        //events_os ev_os;
    public:
        const char* token;
        bool bot = true;

        bool initialised;
        bool connected = true;
        bool ConClose;
        bool retry;
        bool paused = false;


        void on_close(clientpp* c, websocketpp::connection_hdl hdl);

        bool get_user(std::string id);

        discordOs(const char* token, bool bot, );
        discordOs(const char* token, bool bot);
        discordOs() {};
        std::thread thread_client;
        socket_msg socket_msg;
        fetched_user fetched_user;
        //client cli;

        //void pause_client();
        //void resume_client();

        //~discord() {};
        //embed emb;
    };
}


/*#pragma once

#include <websocketpp/config/asio_client.hpp>
#include <websocketpp/client.hpp>
#include <websocketpp/transport/asio/security/tls.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/function.hpp>

#define CPPHTTPLIB_OPENSSL_SUPPORT

#include <httplib.h>
#define _WINSOCK2API_
#define _WINSOCKAPI_    Prevent inclusion of winsock.h in windows.h 

#pragma comment(lib, "libboost_date_time-vc142-mt-s-x64-1_79.lib")
#pragma comment(lib, "libboost_random-vc142-mt-s-x64-1_79.lib")
#pragma comment(lib, "libs/libcurl_a.lib")
#pragma comment(lib, "libs/libssl.lib")



typedef websocketpp::config::asio_client::message_type::ptr message_ptr;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

namespace discordOs
{
#define clientpp websocketpp::client<websocketpp::config::asio_tls_client>

    template <typename hdl_prm>
    struct events_os {
       
        std::vector<handler_param> event_objects;
        std::operator
       
        enum event_codes {
            on_login = 0,
            on_msg = 1,
            on_invalid = 2
        };

        events_os std::operator[](hdl_prm handler_param);
        
        struct event_objects {
            client client;
            discord& disc;
            client::message msg;
        };
    };

    //events_os events_os;

    struct client
    {
        bool initialised;
        std::string prefix;
        std::string id;
        std::string username;
        std::string discriminator;

        std::vector<std::string> guilds;

        struct message
        {
            std::string response;
            std::string author;
            std::string discriminator;
            std::string content;
            std::string channelid;
            std::string id;
            std::string guild_id;

            void respond(client::message* msg, std::string message);

            void command(std::string command, void(*func)(client::message msg));

            std::vector<std::string> param;
            char prefix = '!';

            friend struct discord;
        };
        message msg;
        
        struct current_channel {};
        void del_message(message* msg, std::string MessageID);
        void del_message(std::string ChannelID, std::string messageid);
        void ban_user(message* msg, std::string id);

        struct friends
        {
            std::vector<std::string> name;
        };
    };

    struct socket_msg
    {
        websocketpp::connection_hdl hdl;
        clientpp* c;

        void send_msg(const char* message);

        //bool request_login(discordOs::discord* _disc);
    };

    struct embed
    {
        std::string color;
        std::string title;
        std::string image;
    };

    struct fetched_user
    {
        bool is_valid;
        std::string id;
        std::string username;
        std::string discriminator;
        std::string avatar;
        std::string profile_url;
        std::string response;
    };

    class discord
    {
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

        bool get_user(std::string id);

        discord(const char* token, bool bot, void(*on_invalid)(discord* _disc), void(*on_msg)(client::message msg), void(*on_login)(client client));
        discord(const char* token, bool bot);
        discord(client client) {};
        discord() {};
        ~discord() {};
        std::thread thread_client;
        socket_msg socket_msg;
        fetched_user fetched_user;
        embed emb;
        client cli;

    private:
        void on_message(clientpp* c, websocketpp::connection_hdl hdl, message_ptr msg);
        void on_close(clientpp* c, websocketpp::connection_hdl hdl, discord* _disc);
        void on_open(clientpp* c, websocketpp::connection_hdl hdl);

        void (*on_invalid)(events_os ev);
        void (*on_msg)(client::message msg);
        void (*on_login)(client client);

        //void on_fail(clientpp* c, websocketpp::connection_hdl hdl, discord* _disc);
        std::error_code ec;
        clientpp c;
    };

    extern bool contains(std::string soos, std::string saas);
    extern bool contains(client::message* msg, std::string saas);
}


*/