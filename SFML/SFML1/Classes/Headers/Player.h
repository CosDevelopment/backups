#pragma once
#include "SFML/Graphics.hpp"
#include "./Physics.h"
#include <string>
#include <map>

class Player : public sf::Sprite, public Physics //inherits all of sprites properties publicly so that the class Player can use them freely.
{
public:
  Player();
  ~Player();
  void update();        // this function handles all updates to player. currently that is movement. later will be health and abilities, and other timers.
  void velocityReset(); // this is to stop movement after keypresses are finished
  void addItem(std::string);
  void displayInventory();

private:
  std::map<std::string, int> inventory;
  std::string base = "./Resources/Spritesheets/NarutoSpriteSheet.png"; //relative path to default texture ( this texture has been deleted. now just a place holder)
  uint8_t health = 0b00110100;                                         // health starts at 100. its in binary , plan on changing health through bitwise operations.
  sf::IntRect SpritePos = sf::IntRect(0, 384, 20, 35);                 // the position of the texture i want to show on the sprite as well as sprite size.
  sf::Texture texture;                                                 // Skin for character. gets initialized in the constructor.
};