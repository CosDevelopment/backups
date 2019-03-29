#pragma once
#include "SFML/Graphics.hpp"
// the begininning of my physics engine. handles basic physics. eventually all physics will be handled with other classes in a
//combined PhysicsEngine class.
class Physics
{
public:
  void setVelocityX(float x);         // set x velocity
  void setVelocityY(float y);         // set y velocity
  void setGravity(float g);           // set gravity
  void setVelocity(float x, float y); // set both x and y velocity
  sf::Vector2f getVelocity();
  float getVelocityX();
  float getVelocityY();
  float getGravity();
  void setJump(bool setting); // tells player whether they are jumping or not.
  bool getJump();             // check to see if the player is still jumping;
  void jump();                // will be used to actually make the player jump and fall.

private:
  float velocityX = 0.0;                                      // default x vel
  float velocityY = 0.0;                                      // default y vel
  sf::Vector2f velocity = sf::Vector2f(velocityX, velocityY); // default sf::Vector2F this will replace the floats later. its redundant to have 3 variables;
  int gravity = 0;                                            // default gravity, will be applied later when rigidBodies are introduced .
  bool isJumping;
  friend class Player; // friend class so that all private members can be accessedd by the Player class, and its abstractions.
};