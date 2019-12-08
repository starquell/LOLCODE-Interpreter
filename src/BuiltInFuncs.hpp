#ifndef LOLCODE_BUILTINFUNCS_HPP
#define LOLCODE_BUILTINFUNCS_HPP

#include "Stack.hpp"

#include <iostream>

namespace lolcode::funcs {

    static const auto print = [] (const auto& context) {
        std::cout << Stack::get().var(_attr(context))->toStdString() << std::endl;
    };

}
#endif //LOLCODE_BUILTINFUNCS_HPP
