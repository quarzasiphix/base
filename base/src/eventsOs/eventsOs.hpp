#pragma once
#include "common.hpp"

struct Ev_Os {
    class events_os {
        template <class hdl>
        struct handle {
            int size;
            const char* name;
            hdl& select;
            
            std::vector<std::string> name;
            std::vector<std::thread> thread;

            bool callback();
            bool append(hdl& ref);

            auto operator[](hdl &hdl);
        };

#ifdef DEV
            namespace nlohmann_lib {
                namespace json {
                    nlohmann::json events;
                    bool get(hdl_ref);
                    bool append();
                }
            }
            using nlohmann_lib;
        class handlers {

        public:
        };
    public:

        int ev_obj_count;
        const char* buffer;

    };
#endif
};

