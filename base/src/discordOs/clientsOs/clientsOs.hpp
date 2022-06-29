#pragma once
#include "common.hpp"



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