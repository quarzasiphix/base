#include "eventsOs.hpp"


bool contains(std::string soos, std::string saas) {

    if (soos.find(saas) != std::string::npos) return true;
    else return false;
}

template<class hdl>
inline bool Evs_Os::eventOs::handle<hdl>::callback()
{
    return false;
}

template<class hdl>
bool Evs_Os::eventOs::handle<hdl>::append(hdl& ref)
{
    return false;
}

template<class hdl>
auto Evs_Os::eventOs::handle<hdl>::operator[](hdl& hdl)
{
    const string buf = hdl;

}

/*template<typename hdl_ref>
bool events_os::handlers<hdl_ref>::callback()
{
    for(int i : size(); i++)
        if(contains(buffer,))
}*/



