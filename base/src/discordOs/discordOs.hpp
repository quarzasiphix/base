#pragma once
#include <websocketpp/config/asio_client.hpp>
#include <websocketpp/client.hpp>
#include <websocketpp/transport/asio/security/tls.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/function.hpp>
#include <nlohmann/json.hpp>

#include "functional"
#define CPPHTTPLIB_OPENSSL_SUPPORT

#include <httplib.h>
#define _WINSOCK2API_
#define _WINSOCKAPI_   /* Prevent inclusion of winsock.h in windows.h */

#pragma comment(lib, "libboost_date_time-vc142-mt-s-x64-1_79.lib")
#pragma comment(lib, "libboost_random-vc142-mt-s-x64-1_79.lib")
#pragma comment(lib, "libs/libcurl_a.lib")
#pragma comment(lib, "libs/libssl.lib")

#include <thread>
#include <vector>


typedef websocketpp::config::asio_client::message_type::ptr message_ptr;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

namespace discordOs
{
#define clientpp websocketpp::client<websocketpp::config::asio_tls_client>

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
        bool request_login(discordOs::discord* _disc);
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
        void on_message(clientpp* c, websocketpp::connection_hdl hdl, message_ptr msg);
        void on_close(clientpp* c, websocketpp::connection_hdl hdl, discord* _disc);
        void on_open(clientpp* c, websocketpp::connection_hdl hdl);

        void (*on_invalid)(discord* _disc);
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

        bool get_user(std::string id);

        discord(const char* token, bool bot, void(*on_invalid)(discord* _disc), void(*on_msg)(client::message msg), void(*on_login)(client client));
        discord(const char* token, bool bot);
        discord(client client);
        discord();
        ~discord();
        struct events_os {
            enum class events;
            extern typedef void (*handler_func)(events);
        };
        std::thread threadClient;
        socket_msg _msg;
        fetched_user fetched;
        embed emb;
        client cli;
        events_os events;
    };

    extern bool contains(std::string soos, std::string saas);
    extern bool contains(client::message* msg, std::string saas);
}