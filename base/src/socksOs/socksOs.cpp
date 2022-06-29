#include "socksOs.hpp"

void socksOs::heartbeat(nlohmann::json hb)
{
    while (running)
    {
        send_msg(hb.dump().c_str());
        Sleep(10000);
    }
}

bool socksOs::sendMsg(const char* msg)
{
    return false;
}
