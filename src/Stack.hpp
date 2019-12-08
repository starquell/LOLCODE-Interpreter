#ifndef LOLCODE_STACK_HPP
#define LOLCODE_STACK_HPP

#include "BaseTypes/All.hpp"

#include <map>
#include <string>
#include <string_view>
#include <memory>

namespace lolcode {

    class Stack {
    private:
        explicit Stack () = default;
    public:
        template <class T>
        void newVar (std::string_view name, const type::Object& obj) {
            vars[name.data()] = std::make_shared<T> (obj);
        }

        auto var (std::string_view name) {
            return vars[name.data()];
        }

        [[nodiscard]] static Stack& get() {
            static Stack programStack;
            return programStack;
        }
    private:
        std::map<std::string, std::shared_ptr<type::Object>> vars;
    };
}
#endif //LOLCODE_STACK_HPP
