#include "./Headers/Player.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <map>
Player::Player() : sf::Sprite()
{
    // Constructure applies default texture (NarutoSpriteSheet.png) to the the created player. will add UI to change later.
    if (!texture.loadFromFile(base))
    {
        std::cout << "file not loaded" << std::endl;
    }
    setScale(1.5f, 1.5f);      // scales sprite from texture, sprites are usually too small. this code may be removed later
    setTexture(texture);       // function that sets texture for sf::Sprite, the base class of Player;
    setTextureRect(SpritePos); // applies texture
    setPosition(20.f, 290.f);  // position on the window that the player starts at.
    inventory["Gold"] = 0;
    inventory["Ruby"] = 0;
    inventory["Rock"] = 0;
}
Player::~Player()
{
}
void Player::update()
{
    velocityX = velocity.x; // sets the velocities
    velocityY = velocity.y;
    move(velocityX, velocityY); // moves player based on what the veocities are set to.
}
void Player::velocityReset()
{
    velocityX = velocity.x = 0; // resets the velocities for the float velocities and the sf:: Vector2<T> velocities.
    velocityY = velocity.y = 0;
}

void Player::displayInventory()
{
    std::cout << "Inventory \n"
              << std::endl;
    std::cout << "Gold " << inventory["Gold"] << std::endl;
    std::cout << "Ruby " << inventory["Ruby"] << std::endl;
    std::cout << "Rock " << inventory["Rock"] << std::endl
              << std::endl;
    ;
}
void Player::addItem(std::string item)
{
    // THIS IS A DEFAULT RIGHT NOW.
    inventory[item]++;
}