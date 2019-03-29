#include "./Headers/Items.h"
#include <ctime>
#include <cmath>
#include <iostream>
#include <string>
Item::Item()
{
    id = (rand() % 3);
    switch (id)
    {
    case 0:
        name = "Gold";
        break;
    case 1:
        name = "Ruby";
        break;
    case 2:
        name = "Rock";
        break;
    }
}
std::string Item::getName()
{
    return name;
}