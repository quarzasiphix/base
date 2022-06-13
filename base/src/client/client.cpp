#include "client.hpp"

namespace discordOs {

    using namespace clientOs;

    discordOs& disc;

    void heartbeat( )//discord* disc)
    {
        nlohmann::json hb;
        hb["op"] = 1;
        hb["d"] = 45000;
        while (disc.connected)
        {
            disc.socket_msg.send_msg(hb.dump().c_str());
            Sleep(10000);
        }
    }


    void discordOs::on_message(clientpp* c, websocketpp::connection_hdl hdl)
    {
    }

    void discordOs::on_close(clientpp* c, websocketpp::connection_hdl hdl) {
        disc.ConClose = true;
        disc.connected = false;
        std::cout << "closed connection" << std::endl;
    }

    void discordOs::on_message(clientpp* c, websocketpp::connection_hdl hdl, message_ptr msg) {
        nlohmann::json t = nlohmann::json::parse(msg->get_payload());
        if (contains(t["t"].dump(), "READY"))
        {
            std::thread(heartbeat).detach();
            if (t["op"].get<int>() == 0 && t["t"].get<std::string>() == "READY")
            {
                cli.id = t["d"]["user"]["id"].get<std::string>();
                cli.discriminator = t["d"]["user"]["discriminator"].get<std::string>();
                cli.username = t["d"]["user"]["username"].get<std::string>();
                if (!t["d"]["guild_id"].is_null())
                    for (int i = 0; i < t["d"]["guilds"].size(); i++)
                        cli.guilds.push_back(t["d"]["guilds"][i]["id"].get<std::string>());
                cli.initialised = true;
                if (on_login) on_login(cli);
            }
        }
        if (contains(t["t"].dump(), "MESSAGE_CREATE"))
        {
            cli.msg.author = t["d"]["author"]["username"].get<std::string>();
            cli.msg.discriminator = t["d"]["author"]["discriminator"].get<std::string>();
            cli.msg.content = t["d"]["content"].get<std::string>();
            cli.msg.channelid = t["d"]["channel_id"].get<std::string>();
            cli.msg.id = t["d"]["id"].get<std::string>();
            if (!t["d"]["guild_id"].is_null())
                cli.msg.guild_id = t["d"]["guild_id"].get<std::string>();
            cli.msg.param = split(cli.msg.content, ' ');
            on_msg(cli.msg);
        }
    }

    void discordOs::on_open(clientpp* c, websocketpp::connection_hdl hdl) {
        if (bot) c->send(hdl, "{\"op\":2,\"d\":{\"token\":\"" + std::string(this->token) + "\", \"intents\":32767, \"properties\":{\"$os\": \"linux\", \"$browser\":\"discord++\", \"$device\":\"discord++\"}}}", websocketpp::frame::opcode::text);
        else    c->send(hdl, "{\"op\":2,\"d\":{\"token\":\"" + std::string(this->token) + "\",\"capabilities\":253,\"properties\":{\"os\":\"Windows\",\"browser\":\"Chrome\",\"device\":\"\",\"system_locale\":\"en-US\",\"browser_user_agent\":\"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/96.0.4664.45 Safari/537.36\",\"browser_version\":\"96.0.4664.45\",\"os_version\":\"10\",\"referrer\":\"\",\"referring_domain\":\"\",\"referrer_current\":\"\",\"referring_domain_current\":\"\",\"release_channel\":\"stable\",\"client_build_number\":108924,\"client_event_source\":null},\"compress\":false,\"client_state\":{\"guild_hashes\":{},\"highest_lastmessage_id\":\"0\",\"read_state_version\":0,\"user_guild_settings_version\":-1,\"user_settings_version\":-1}}}", websocketpp::frame::opcode::text);
        socket_msg.hdl = hdl;
        socket_msg.c = c;
        this->connected = true;
    }

    discordOs::discord(const char* token, bool bot)
    {
        this->on_invalid = on_invalid;
        this->on_login = on_login;
        this->on_msg = on_msg;
        discord(token, bot);
    }

    discordOs::discord(const char* token, bool bot)
    {
        thread_client = std::thread([=]()
            {
                if (bot == true)
                    headers.emplace("Authorization", "Bot " + std::string(token));
                else headers.emplace("Authorization", token);

                headers.emplace("User-Agent", "Discord");

                c.set_tls_init_handler([this](websocketpp::connection_hdl) {
                    return websocketpp::lib::make_shared<boost::asio::ssl::context>(boost::asio::ssl::context::tlsv1);
                    });

                try {
                    c.init_asio();
                    //c.set_fail_handler   (std::bind(&discordOs::on_fail,    this, &c, ::_1, this));
                    c.set_access_channels(websocketpp::log::alevel::none);
                    c.set_message_handler(std::bind(&discordOs::on_message, this, &c, ::_1, ::_2)); //set event handlers, on_close and on_error are also possible.
                    c.set_open_handler(std::bind(&discordOs::on_open, this, &c, ::_1));
                    c.set_close_handler(std::bind(&discordOs::on_close, this, &c, ::_1, this));

                    websocketpp::lib::error_code ec;
                    clientpp::connection_ptr con = c.get_connection(uri, ec);
                    if (ec) {
                        std::cout << "could not create connection because: " << ec.message() << std::endl;
                        return;
                    }
                    c.connect(con);
                    this->initialised = true;
                    c.run();
                }

                catch (nlohmann::json::exception& e)
                {
                    MessageBoxA(nullptr, e.what(), nullptr, MB_OK);
                }
                catch (websocketpp::exception const& e)
                {
                    MessageBoxA(nullptr, e.what(), nullptr, MB_OK);
                }
                catch (...)
                {
                    MessageBoxA(nullptr, "unknown", nullptr, MB_OK);
                }
            });
        thread_client.detach();
    }

    bool discordOs::get_user(std::string id)
    {
        httplib::SSLClient cli("discord.com");
        std::string url = "https://discord.com/api/v9/users/" + id;
        auto res = cli.Get(url.c_str(), headers);
        nlohmann::json t = nlohmann::json::parse(res->body);
        fetched_user.response = res->body;
        if (contains(res->body, "error")) return false;
        fetched_user.id = t["id"].get<std::string>();
        fetched_user.username = t["username"].get<std::string>();
        fetched_user.discriminator = t["discriminator"].get<std::string>();
        fetched_user.avatar = t["avatar"].get<std::string>();
        fetched_user.profile_url = std::string("https://cdn.discordapp.com/avatars/" + fetched.id + "/" + fetched.avatar + ".webp?size=160");
        cli.stop();

        return true;
    }

    discordOs::discordOs(const char* token, bool bot)
    {
    }
}
