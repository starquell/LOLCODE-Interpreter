#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include "Parser.hpp"

#include <stdexcept>
#include <string>

namespace lolcode {

    template <typename IStream>
    void interpret (IStream& stream) {
        if (!stream.is_open()) 
            throw std::runtime_error("File is not opened.");
        
        std::string line;
        while (std::getline(stream, line)) {
            parser::parse(line);
        }
    }
}
#endif