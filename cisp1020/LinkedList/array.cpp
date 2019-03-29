#include <iostream>
#include <array>
#include <string>

int main()
{

    std::array<std::string, 3> names;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Enter a name: ";
        std::cin >> names[i];
    }
    for (auto i = names.rbegin(); i != names.rend(); i++)
    {
        std::cout << "Hi " << *i << std::endl;
    }

    return 0;
}