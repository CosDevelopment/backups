
#include "./EzyC/Common.hpp"

int main(int argc, char* argv[]){



    EzyC::Tokenizer::start(argv[1]);
    //EzyC::Tokenizer::Tokenize(lines);
    std::cout<<rang::fg::red<<"happened"<<std::regex_match("=",EzyC::RegExStmnts::ASSIGNMENT)<<std::endl;
    return 0;
}