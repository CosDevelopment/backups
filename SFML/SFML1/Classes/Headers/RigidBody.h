#pragma once
#include "SFML/Graphics.hpp"
// TODO ignore this, this is a WIP
class RigidBody
{
public:
  RigidBody();
  void setCollision();
  void setKinetic();
  void setHitBox();
  sf::Vector2f getHitBox();

private:
  sf::Vector2f hitbox = sf::Vector2f(40.f, 30.f);
  bool canCollide = false;
  bool kinetic = false;
};