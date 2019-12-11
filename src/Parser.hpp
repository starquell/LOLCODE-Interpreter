#ifndef PARSER_HPP
#define PARSER_HPP

#include "BaseTypes/All.hpp"
#include "Rules.hpp"
#include "Stack.hpp"
#include "BuiltInFuncs.hpp"

#include <iostream>

namespace lolcode::parser {

    static const auto nullToStack = [] (const auto& context) {
        Stack::get().newVar <type::Object>(_attr(context), type::Object{});
    };

    auto parse (std::string_view str) {
        phrase_parse(str.begin(), str.end(),
                     rules::declaration[nullToStack] | rules::print[funcs::print],
                     ascii::space);
    }
}

#endif