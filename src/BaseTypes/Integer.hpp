#ifndef LOLCODE_INTEGER_HPP
#define LOLCODE_INTEGER_HPP

#include "Object.hpp"
#include "String.hpp"

#include <string>
#include <iostream>
#include <algorithm>

namespace type {

   class Integer : public Object {
   public:
       Integer()
            : m_value (0)
       {}
       Integer(int value)
            : m_value (value)
       {}

       friend bool operator> (const Integer& lhs, const Integer& rhs);
       friend bool operator< (const Integer& lhs, const Integer& rhs);
       friend bool operator>= (const Integer& lhs, const Integer& rhs);
       friend bool operator<= (const Integer& lhs, const Integer& rhs);
       friend bool operator== (const Integer& lhs, const Integer& rhs);
       friend bool operator!= (const Integer& lhs, const Integer& rhs);

       friend Integer operator+ (const Integer& lhs, const Integer& rhs);
       friend Integer operator- (const Integer& lhs, const Integer& rhs);
       friend Integer operator* (const Integer& lhs, const Integer& rhs);
       friend Integer operator/ (const Integer& lhs, const Integer& rhs);
       friend Integer operator% (const Integer& lhs, const Integer& rhs);

       friend String operator* (const String& lhs, const Integer& rhs);

       friend std::istream& operator>> (std::istream& stream, Integer& integer);
       friend std::ostream& operator<< (std::ostream& stream, const Integer& integer);

   private:
       int m_value;
   };

    bool operator> (const Integer& lhs, const Integer& rhs) {
        return lhs.m_value > rhs.m_value;
    }
    bool operator< (const Integer& lhs, const Integer& rhs) {
        return lhs.m_value < rhs.m_value;
    }
    bool operator>= (const Integer& lhs, const Integer& rhs) {
        return lhs.m_value >= rhs.m_value;
    }
    bool operator<= (const Integer& lhs, const Integer& rhs) {
        return lhs.m_value <= rhs.m_value;
    }
    bool operator== (const Integer& lhs, const Integer& rhs) {
        return lhs.m_value == rhs.m_value;
    }
    bool operator!= (const Integer& lhs, const Integer& rhs) {
        return lhs.m_value != rhs.m_value;
    }

    Integer operator+ (const Integer& lhs, const Integer& rhs) {
        return lhs.m_value + rhs.m_value;
    }
    Integer operator- (const Integer& lhs, const Integer& rhs) {
        return lhs.m_value - rhs.m_value;
    }
    Integer operator* (const Integer& lhs, const Integer& rhs) {
        return lhs.m_value * rhs.m_value;
    }
    Integer operator/ (const Integer& lhs, const Integer& rhs) {
        return lhs.m_value / rhs.m_value;
    }
    Integer operator% (const Integer& lhs, const Integer& rhs) {
        return lhs.m_value % rhs.m_value;
    }
    std::istream& operator>> (std::istream& stream, Integer& integer) {
        return stream >> integer.m_value;
    }
    std::ostream& operator<< (std::ostream& stream, const Integer& integer) {
       return stream << integer.m_value;
    }

    String operator* (const String& lhs, const Integer& rhs) {
        String temp;
        temp.reserve(rhs.m_value * lhs.size());
        for (int i = 0; i < rhs.m_value - 1; ++i)
            temp += temp;
        return temp;
    }
}
#endif //LOLCODE_INTEGER_HPP
