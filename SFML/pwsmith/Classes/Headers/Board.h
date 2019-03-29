#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Items.h"
#include <string>

enum Mode {
    Edit,
    Play
};
class Board : public sf::Sprite
{
  public:
    Board();
    void query(Player &player);
    void query();
    void setMode(Mode mode);
    bool getMode();
    void addObject(sf::RenderWindow &window);
    Item arrayOfObjects[15];
    Item treasure;
  private:
    int objects = -1;
    bool editMode = false;
    sf::Texture texture; // texture object for the class
    std::string base = "./Resources/Backgrounds/KonohaStage1.png"; // base texture
    
};