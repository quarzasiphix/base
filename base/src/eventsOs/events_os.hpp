#pragma once
#include "common.hpp"

namespace Ev_Os
{
    struct events_os {
        template <typename hdl_ref>
        class handlers {
            const char* buffer;
            struct handle {
                std::vector<hdl_ref> hdl_ref;
                std::vector<std::string> hdl_name;
            };
        public:
            void add();
            void call();
            events_os operator[](const char* hdl);
            handle handle;
        };
    };
}
