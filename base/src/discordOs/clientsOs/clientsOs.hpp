#pragma once
#include "common.hpp"

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


namespace discordOs {
    namespace clientOs {
        /*struct embed // deprecated 
        {
            std::string color;
            std::string title;
            std::string image;
        };*/
        struct fetchedU
        {
            bool is_valid;
            std::string id;
            std::string username;
            std::string discriminator;
            std::string avatar;
            std::string profile_url;
            std::string response;
        };
    }

    struct clientOs
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

            void respond(std::string message);

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
}