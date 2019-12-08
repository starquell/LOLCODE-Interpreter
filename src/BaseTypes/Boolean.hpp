#ifndef LOLCODE_BOOLEAN_HPP
#define LOLCODE_BOOLEAN_HPP

#include "Object.hpp"

#include <cassert>

#include <string_view>

namespace type {

    class Boolean {
    public:
        constexpr static std::string_view True = "WIN";
        constexpr static std::string_view False = "FAIL";

        Boolean()
            : m_value (false)
        {}
        Boolean (std::string_view value) {
            assert (value == True || value == False);
            m_value = value == True;
        }

        using value_type = bool;

        operator bool() {
            return m_value;
        }

        friend std::istream& operator>> (std::istream& stream, Boolean& integer);
        friend std::ostream& operator<< (std::ostream& stream, const Boolean& integer);

    private:
        bool m_value;
    };

    std::istream& operator>> (std::istream& stream, Boolean& boolean) {
        return stream >> boolean;
    }
    std::ostream& operator<< (std::ostream& stream, const Boolean& boolean) {
        return stream << boolean;
    }
}

#endif //LOLCODE_BOOLEAN_HPP
