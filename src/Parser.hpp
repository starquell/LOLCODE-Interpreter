#include "BaseTypes/All.hpp"

#include <boost/spirit/home/x3/support/ast/variant.hpp>
#include <boost/spirit/home/x3.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <type_traits>

namespace parser {
    namespace x3 = boost::spirit::x3;
    namespace ascii = boost::spirit::x3::ascii;

    namespace ast {
        using Variable = x3::variant <type::Integer,
                                      type::Float,
                                      type::String,
                                      type::Boolean,
                                      std::string>;
    }

    namespace rules {
        const inline static x3::rule <class String, type::String> string = "string";
        const inline static x3::rule <class Integer, type::Integer> integer = "integer";
        const inline static x3::rule <class Float, type::Float> floating = "float";
        const inline static x3::rule <class Boolean, type::Boolean> boolean = "bool";
        const inline static x3::rule <class Null, std::string> null = "null";

        const inline static x3::rule <class Boolean, ast::Variable> variable = "variable";

        namespace {
            const auto string_def = x3::lexeme['"' >> *(x3::char_ - '"') >> '"'];
            const auto integer_def = x3::int_ >> !x3::lexeme["."];
            const auto floating_def = x3::double_;
            const auto boolean_def = x3::lit("WIN") | x3::lit("FAIL") ;
            const auto null_def = x3::lit("NOOB");

            const auto variable_def = integer | floating | string | boolean | null;
        }

        BOOST_SPIRIT_DEFINE(string,
                            integer,
                            floating,
                            boolean,
                            null,
                            variable)
    }

    static const auto action = [] (const auto& context) {
        std::cout << _attr(context) << std::endl;};

    auto parse_str (std::string_view str) {
        phrase_parse(str.begin(), str.end(),
                    rules::string[action] % ',',
                    ascii::space);
    }
}