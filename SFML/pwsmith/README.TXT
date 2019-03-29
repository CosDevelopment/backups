`````````````````` INSTRUCTIONS `````````````
: Move Left - left arrow key
: Move Right - right arrow key
: Query board for player position : D key
: Query board for whether there are items on the map - S key
: Pick up Treasure : B
: enter Edit Mode : E , leave with P
: Right click places blocks in Edit Mode
: Inventory : I 
`````````````````` INFORMATION `````````````
: Currently the player is White, th original default texture is no longer going to be used, I am looking for another.
: Currently the player can leave the bounds of the board, this will be fixed.
: Currently the board never initialized a treasure item on the map, but it does have a treasure item inside of the object. 
: Thank you for playing!

````````````````` COMMAND TO COMPILE ```````
g++ game.cpp ./Classes/Player.cpp ./Classes/Board.cpp ./Classes/RigidBody.cpp ./Classes/Physics.cpp -o window -lsfml-graphics -lsfml-window -lsfml-system -std=c++11 