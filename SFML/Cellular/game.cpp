#include "SFML/Graphics.hpp"
#include "./Classes/Headers/Board.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1360,760), "SFML works!");
    Board board;
  
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}