#include "./Headers/Physics.h"
void Physics::setJump(bool setting)
{ isJumping = setting;} // sets jumping for physics object

bool Physics::getJump() // returns jumping for physics object.
{return isJumping;}

void Physics::jump()
{/*... TODO*/}

void Physics::setVelocityX(float x) // sets all values of x velocity
{velocity.x = velocityX = x; }

void Physics::setVelocityY(float y)// sets all values of y velocity
{ velocity.y =velocityY = y;}

void Physics::setGravity(float g)// sets gravity value;
{gravity = g;}

float Physics::getVelocityX()// gets x velocity
{return velocityX;}

float Physics::getVelocityY()// gets y velocity
{return velocityY;}

sf::Vector2f Physics::getVelocity()// gets velocity for both x and y
{return velocity;}

void Physics::setVelocity(float x, float y) // sets the velocity for both x and y 
{ velocityX = x; velocityY = y;}
 
float Physics::getGravity()// gets gravity 
{return gravity;}