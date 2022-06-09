#include "events_os.hpp"

namespace Ev_Os
{
    /*template <typename in>
    bool contains(in in, std::string saas) {
        if (msg->content.find(saas) != std::string::npos && msg->content.find(saas) < (saas.size() + 1)) return true;
        else return false;
    }*/

    bool contains(std::string soos, std::string saas) {

        if (soos.find(saas) != std::string::npos) return true;
        else return false;
    }

    template <typename Out>
    void split(const std::string& s, char delim, Out result) {
        std::istringstream iss(s);
        std::string item;
        while (std::getline(iss, item, delim)) {
            *result++ = item;
        }
    }

    std::vector<std::string> split(const std::string& s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, std::back_inserter(elems));
        return elems;
    }


    template <typename hdl_ref>
    void events_os::handlers<hdl_ref>::call()
    {
        for (int i = 0; i < handle.size(); i++)
        {
            if(contains(handle.hdl_name[i], buffer))
                handle.
        }

    }

    template<typename hdl_ref>
    events_os events_os::handlers<hdl_ref>::operator[](const char* hdl)
    {
        buffer = hdl;
        return(operator[](buffer));
    }
}
