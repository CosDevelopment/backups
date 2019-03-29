#pragma once
#include <string>
#include "SFML/Graphics.hpp"
class Item : public sf::RectangleShape
{
  public:
    Item();
    static int getItemId(Item item);
    bool exist;
    std::string getName();

  private:
    int id;
    std::string name;
    sf::RectangleShape item;
    enum class items
    {
        GOLD = 0,
        RUBY = 1,
        ROCK = 2
    };
};