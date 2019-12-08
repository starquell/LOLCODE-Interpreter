#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>

namespace lolcode::type {
    class Object {
    public:
        [[nodiscard]] virtual std::string toStdString() const {
            return "NOOB";
        }
        virtual ~Object() = default;
    };
}
#endif