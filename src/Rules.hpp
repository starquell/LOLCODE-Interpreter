#ifndef LOLCODE_RULES_HPP
#define LOLCODE_RULES_HPP

#include "BaseTypes/All.hpp"

#include <boost/spirit/home/x3/support/ast/variant.hpp>
#include <boost/spirit/home/x3.hpp>
#include <string>
#include <utility>

namespace lolcode::parser {
    namespace x3 = boost::spirit::x3;
    namespace ascii = boost::spirit::x3::ascii;

    namespace ast {
        using Variable = x3::variant<lolcode::type::Integer,
                                     lolcode::type::Float,
                                     lolcode::type::String,
                                     lolcode::type::Boolean,
                                     std::string>;
    }

    namespace rules {
        const inline static x3::rule<class String, type::String> string = "string";
        const inline static x3::rule<class Integer, type::Integer> integer = "integer";
        const inline static x3::rule<class Float, type::Float> floating = "float";
        const inline static x3::rule<class Boolean, type::Boolean> boolean = "bool";

        const inline static x3::rule<class Boolean, ast::Variable> literal = "literal";
        const inline static x3::rule<class VarName, std::string> varName = "varName";
        const inline static x3::rule<class Declaration, std::string> declaration = "declaration";
        const inline static x3::rule<class DeclAndDef, std::pair<std::string, ast::Variable>> declAndDef = "declAndDef";
        const inline static x3::rule<class Comment, x3::unused_type> comment = "comment";

        const inline static x3::rule<class Print, std::string> print = "print";

        namespace {
            const auto string_def = x3::lexeme['"' >> *(x3::char_ - '"') >> '"'];
            const auto integer_def = x3::int_ >> !x3::lexeme["."];
            const auto floating_def = x3::double_;
            const auto boolean_def = x3::lit("WIN") | x3::lit("FAIL");

            const auto literal_def = integer | floating | string | boolean;
            const auto varName_def = x3::alpha >> *x3::alnum;
            const auto declaration_def = x3::lit("I HAS A ") >> varName;
            const auto declAndDef_def = declaration >> x3::lit(" ITZ ") >> literal;
            const auto comment_def = x3::lit("BTW") >> *x3::char_;

            const auto print_def = x3::lit("VISIBLE") >> varName;
        }

        BOOST_SPIRIT_DEFINE(string,
                integer,
                floating,
                boolean,
                literal,
                varName,
                declaration,
                comment,
                print
        )
    }
}
#endif //LOLCODE_RULES_HPP
