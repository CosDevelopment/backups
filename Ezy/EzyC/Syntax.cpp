#include "Syntax.hpp"
#include <regex>

namespace EzyC{

    const std::regex RegExStmnts::ASSIGNMENT{"^(=)"};
    const std::regex RegExStmnts::TYPE{"(int|string|char|bool|double|float)"};
    const std::regex RegExStmnts::VAR_NAME{"\d"};
    const std::regex RegExStmnts::START{"(main:)"};


}