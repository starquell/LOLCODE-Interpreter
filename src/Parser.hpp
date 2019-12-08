#include "BaseTypes.hpp"

#include <boost/spirit/home/x3.hpp>
#include <string>
#include <iostream>
#include <vector>

namespace parser {
    namespace x3 = boost::spirit::x3;
    namespace ascii = boost::spirit::x3::ascii;

    namespace ast {
        struct Variable :
                public boost::variant <type::Integer,
                                       type::Floating,
                                       type::String,
                                       type::Boolean,
                                       type::Null> {
            Variable (type::Null null = type::Null{})
                : boost::variant(null)
            {}
            Variable (const std::string& str) {

            }
        };
    }

    namespace rules {
        const inline static x3::rule <class String, std::string> string = "string";
        const inline static x3::rule <class Integer, int> integer = "integer";
        const inline static x3::rule <class Float, double> floating = "float";
        const inline static x3::rule <class Boolean, std::string> boolean = "bool";

        const inline static x3::rule <class Boolean, std::string>

        namespace {
            const auto string_def = x3::lexeme['"' >> *(x3::char_ - '"') >> '"'];
            const auto integer_def = x3::int_ >> !x3::lexeme["."];
            const auto floating_def = x3::double_;
            const auto boolean_def = x3::lit("WIN") | x3::lit("FAIL");
        }

        BOOST_SPIRIT_DEFINE(string,
                            integer,
                            floating,
                            boolean)
    }

    static const auto action = [] (const auto& context) {std::cout << _attr(context) << std::endl;};

    auto parse_str (std::string_view str) {
        phrase_parse(str.begin(), str.end(),
                     (parser::rules::boolean[action]
                     | parser::rules::string[action]
                     | parser::rules::integer[action]
                     | parser::rules::floating[action]) % ',',
                     ascii::space);
    }
}