#pragma once
#include "common.hpp"

namespace Ev_Os {
    struct events_os {
        template <typename hdl_ref>
        class handle : public events_os {
            const char* handle_name;
            void(*select_handler)(hdl_ref& hdl);
            std::vector < std::function<void(*)(hdl_ref& handle)>& hdl_ref;
            std::vector<std::string> hdl_name;
            std::vector<std::thread> hdl_thread;
        public:
            int size();
            bool append(const char* hdl_name, hdl_ref& ref);
        };

        template <typename hdl_ref>
        struct handlers {
            namespace nlohmann_lib {
                namespace json {
                    nlohmann::json events;
                    bool get(hdl_ref);
                    bool append();
                }
            }

            using nlohmann_lib;
        };
    public:

        int ev_obj_count;
        const char* buffer;

        events_os operator[](std::string ref_name);
    };
}
