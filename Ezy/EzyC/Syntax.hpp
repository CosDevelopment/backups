#ifndef SYNTAX_HPP // include guard
#define SYNTAX_HPP
#include "Common.hpp"
#include <regex>
namespace EzyC {
    struct RegExStmnts {
    private:

    public:

        static const std::regex ASSIGNMENT;
        static const std::regex TYPE;
        static const std::regex VAR_NAME;
        static const std::regex START;
    };

    class SyntaxAnalyzer {
    public:
        static void build(std::vector<std::vector<std::string>> tokens) {
            for (auto line:tokens) {
                for (auto token:line) {
                    //  if(std::regex_match( token.front(),RegExStmnts::START)){std::cout<<"found main"<<std::endl; return;}

                }
            }
        };


    };
}
#endif 