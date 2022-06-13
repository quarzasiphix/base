#include "events_os.hpp"

namespace Ev_Os
{
    bool contains(std::string soos, std::string saas) {

        if (soos.find(saas) != std::string::npos) return true;
        else return false;
    }

    template<typename hdl_ref>
    int events_os::handle<hdl_ref>::size()
    {
        return 0;
    }

    template<typename hdl_ref>
    bool events_os::handle<hdl_ref>::append(const char* hdl_name, hdl_ref& ref)
    {
        return false;
    }


    events_os events_os::operator[](std::string ref_name)
    {
        return events_os();
    }
}
