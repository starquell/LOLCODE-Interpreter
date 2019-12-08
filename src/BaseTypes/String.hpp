#ifndef LOLCODE_STRING_HPP
#define LOLCODE_STRING_HPP

#include "Object.hpp"

#include <string>
#include <utility>

namespace type {

    class String : public Object,
                   public std::string {
    public:
        String () = default;
        String (std::string str)
            : std::string (std::move(str))
        {}
    };

    String& operator+= (String& lhs, const String& rhs) {
        lhs.append(rhs);
        return lhs;
    }
}

#endif //LOLCODE_STRING_HPP
