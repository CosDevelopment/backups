#include <iostream>
#include <list>
#include <string>

int main()
{

    std::string name;
    std::list<std::string> names;
    
    std::cout << "Enter a name: ";
    std::cin>>name;
    while (name != "johnny")
    {
        names.push_back(name);
        std::cout << "Enter a name: ";
        std::cin>>name;
    }
    for (auto i = names.rbegin(); i != names.rend(); i++)
    {
        std::cout << "Hi " << *i << std::endl;
    }

    return 0;
}