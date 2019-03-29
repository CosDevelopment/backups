#include "./Headers/Board.h"
#include <iostream>
#include "./Headers/Items.h"
Board::Board() : sf::Sprite()
{
    treasure.setSize(sf::Vector2f(20.f,20.f));
    treasure.exist = true;
    treasure.setFillColor(sf::Color::Cyan);
    treasure.setPosition(sf::Vector2f(180.f,290.f));
    // Constructure applies default/base  texture to the the created player. will add UI to change later.
    if (!texture.loadFromFile(base))
    {
        std::cout << "file not loaded" << std::endl;
    }
    setTexture(texture); // function that sets texture for sf::Sprite, the base class of board;
}
void Board::query(Player &player){
  std::cout<<"you are standing at position "<<player.getPosition().x<<","<<player.getPosition().y<<std::endl;
    
}
void Board::query(){
  if(!treasure.exist){
      std::cout<<"there are no items in this stage"<<std::endl;
  }else{
      std::cout<<"THERE IS TREASURE!"<<std::endl;
  }
    
}
void Board::setMode(Mode mode){
     if(mode == Mode::Edit){
         editMode = true;
        }
        else{
            editMode = false;
        }

    }
bool Board::getMode(){
     return editMode;

    }
    void Board::addObject(sf::RenderWindow &window){
        objects ++;
        if(objects <15){
        arrayOfObjects[objects].setSize(sf::Vector2f(20.f,20.f));
        arrayOfObjects[objects].setFillColor(sf::Color::Red);
        arrayOfObjects[objects].setPosition(sf::Vector2f((float)(sf::Mouse::getPosition(window).x),(float)(sf::Mouse::getPosition(window).y)));
        std::cout<<"worked"<<std::endl;
        }
        
    }