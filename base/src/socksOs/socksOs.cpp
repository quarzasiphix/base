#include "socksOs.hpp"



socksOs::socksOs()
{
    c.init_asio();
    //c.set_fail_handler   (std::bind(&discordOs::on_fail,    this, &c, ::_1, this));
    c.set_access_channels(websocketpp::log::alevel::none);
    c.set_message_handler(std::bind(&on_message, this, &c, ::_1, ::_2)); //set event handlers, on_close and on_error are also possible.
    c.set_open_handler(std::bind(&on_open, this, &c, ::_1));
    c.set_close_handler(std::bind(&on_close, this, &c, ::_1, this));

    websocketpp::lib::error_code ec;
    clientpp::connection_ptr con = c.get_connection(uri, ec);
    if (ec) {
        std::cout << "could not create connection because: " << ec.message() << std::endl;
        return;
    }
    c.connect(con);
    
}

void socksOs::heartbeat(nlohmann::json hb)
{
    while (running)
    {
        sendMsg(hb.dump().c_str());
        Sleep(10000);
    }
}

bool socksOs::sendMsg(const char* msg)
{
    c->send(hdl, msg, websocketpp::frame::opcode::text);
    return false;
}