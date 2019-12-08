#include "src/Parser.hpp"
#include <iostream>
#include <fstream>


int main (int argc, char** argv) {

     //parser::parse_str(R"(325235325, 23323.1, 23232, 32, "Hello fren", 31244, "ou", 23.2, WIN)");
 //   lolcode::parser::parse_str(R"("325235325", "23323.1", "23232", "32", "Hello fren", "31244", "ou", "23.2", "WIN")");
    lolcode::parser::parse("I HAS A var");
    lolcode::parser::parse("VISIBLE var");
    return 0;
}