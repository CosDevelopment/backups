#include "SFML/Graphics.hpp"
#include "./Classes/Headers/Player.h"
#include "./Classes/Headers/Board.h"
#include "./Classes/Headers/Physics.h"
#include "./Classes/Headers/Items.h"
#include <iostream>
#include<ctime>
#include<cmath>
const int HEIGHT = 350; // Screen res
const int WIDTH = 640;

int main(int argc, char **argv)
{
   srand(time(0));
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Naruto!"); // Creation of sf::RenderWindow (inherrits sf::Window))
    window.setFramerateLimit(60);
    Player *mainCharacter = new Player(); // Player is a derived class of sf::Sprite. added my own layer of abstraction to add more to my sprites.
    Board *Stage1 = new Board();
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event)) //checks for evens to be handles.
        {
            if (event.key.code == sf::Keyboard::Left)
                mainCharacter->setVelocityX(-4.0f); // if left is pressed, call the physics class's setVelocityX function. this caushes movement to the left

            if (event.key.code == sf::Keyboard::Right)// if left is pressed, call the physics class's setVelocityX function. this caushes movement to the right
                mainCharacter->setVelocityX(4.0f);

            if (event.key.code == sf::Keyboard::D)//queries player location on the board and sees if you can pick up an item.
                Stage1->query(*mainCharacter);
            if (event.key.code == sf::Keyboard::S)//queries whether there is an item on the board.
                Stage1->query();
            if (event.key.code == sf::Keyboard::E){  // activates edit mode.
                Stage1->setMode(Mode::Edit);    
                std::cout<<"Mode:: Edit Mode activated"<<std::endl;
            }
            if (event.key.code == sf::Keyboard::I){ // display inventory.
                (*mainCharacter).displayInventory();
            }
            if (event.key.code == sf::Keyboard::P){// exit edit mode.
                Stage1->setMode(Mode::Play);    
                std::cout<<"Mode::Play Mode activated"<<std::endl;
            }
            if (event.key.code == sf::Keyboard::B){// pick up treasure.
               if(Stage1->treasure.exist){ 
                Stage1->treasure.exist = false;
                (*mainCharacter).addItem(Stage1->treasure.getName());
               }
            }
            if (event.type == sf::Event::Closed)
                window.close();
            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)){// activates edit mode.
                if(Stage1->getMode()){
                    Stage1->addObject(window);
                }
            }
        }
       
        mainCharacter->update(); // this calls an update to the player. for right now this is what controls the movement per loop;
        mainCharacter->velocityReset(); // this is to reset velocity when keys are not being pressed. hold the key down and you will continue moving.
        window.clear(); //clears window for update, however there is no updates to this window.
        window.draw(*Stage1);
         for(Item object : (*Stage1).arrayOfObjects){
            window.draw(object);
        }
        if((*Stage1).treasure.exist){
                window.draw((*Stage1).treasure);
        }
        window.draw(*mainCharacter); // draw MainPlayer to the screen.
        window.display();
    }
    return 0;
}
