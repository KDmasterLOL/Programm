#pragma once
#include "GameObject.hpp"
class Player : public GameObject
{
private:
    float speed;

public:
    Player(SDL_Texture *texture, SDL_Rect rect, float speed) : GameObject(texture, rect)
    {
        this.speed = speed;
    }
    void Move(char direction)// Move player U - up D - down L - left R - right
    {
        if(direction = 'U') 
        else if(direction = 'D')
        else if(direction = 'L')
        else if(direction = 'R')
    }
    void Jump()
    {
    }
    void Colision()
    {
    }
};