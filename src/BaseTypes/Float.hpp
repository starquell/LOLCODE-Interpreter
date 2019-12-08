#ifndef LOLCODE_FLOATING_HPP
#define LOLCODE_FLOATING_HPP

#include "Object.hpp"

#include <iostream>

namespace type {

    class Float : public Object {
    public:
        Float()
                : m_value (0.0f)
        {}
        Float(double value)
                : m_value (value)
        {}

        using value_type = double;
        Float& operator= (const Float& other) {
            m_value = other.m_value;
            return *this;
        }

        friend bool operator> (const Float& lhs, const Float& rhs);
        friend bool operator< (const Float& lhs, const Float& rhs);
        friend bool operator>= (const Float& lhs, const Float& rhs);
        friend bool operator<= (const Float& lhs, const Float& rhs);
        friend bool operator== (const Float& lhs, const Float& rhs);
        friend bool operator!= (const Float& lhs, const Float& rhs);

        friend Float operator+ (const Float& lhs, const Float& rhs);
        friend Float operator- (const Float& lhs, const Float& rhs);
        friend Float operator* (const Float& lhs, const Float& rhs);
        friend Float operator/ (const Float& lhs, const Float& rhs);

        friend std::istream& operator>> (std::istream& stream, Float& integer);
        friend std::ostream& operator<< (std::ostream& stream, const Float& integer);

    private:
        double m_value;
    };

    bool operator> (const Float& lhs, const Float& rhs) {
        return lhs.m_value > rhs.m_value;
    }
    bool operator< (const Float& lhs, const Float& rhs) {
        return lhs.m_value < rhs.m_value;
    }
    bool operator>= (const Float& lhs, const Float& rhs) {
        return lhs.m_value >= rhs.m_value;
    }
    bool operator<= (const Float& lhs, const Float& rhs) {
        return lhs.m_value <= rhs.m_value;
    }
    bool operator== (const Float& lhs, const Float& rhs) {
        return lhs.m_value == rhs.m_value;
    }
    bool operator!= (const Float& lhs, const Float& rhs) {
        return lhs.m_value != rhs.m_value;
    }
    Float operator+ (const Float& lhs, const Float& rhs) {
        return lhs.m_value + rhs.m_value;
    }
    Float operator- (const Float& lhs, const Float& rhs) {
        return lhs.m_value - rhs.m_value;
    }
    Float operator* (const Float& lhs, const Float& rhs) {
        return lhs.m_value * rhs.m_value;
    }
    Float operator/ (const Float& lhs, const Float& rhs) {
        return lhs.m_value / rhs.m_value;
    }

    std::istream& operator>> (std::istream& stream, Float& floating) {
        return stream >> floating.m_value;
    }
    std::ostream& operator<< (std::ostream& stream, const Float& floating) {
        return stream << floating.m_value;
    }

}

#endif //LOLCODE_FLOATING_HPP
