#pragma once
#include "GameObjectClass.hpp"
class Player : public GameObjectClass
{
private:
    float speed;
    const map_keys &keys;
    int x = 0, y = 0;

public:
    Player(SDL_Texture *texture, SDL_FRect rect, SDL_Rect rect_window, map_game_objects_class &game_objects, float speed, const map_keys &keys)
        : GameObjectClass(texture, rect, rect_window, game_objects), keys(keys)
    {
        this->speed = speed;
    }
    void Update()
    {
        Move();
    }
    void Move() // Move player U - up D - down L - left R - right
    {
        try
        {
            if (keys.at(SDLK_w))
                rect.y -= speed;
            if (keys.at(SDLK_s))
                rect.y += speed;
            if (keys.at(SDLK_a))
                rect.x -= speed;
            if (keys.at(SDLK_d))
                rect.x += speed;
        }
        catch (std::out_of_range exc)
        {
            
        }
    }

    void Jump()
    {
    }
    void Colision()
    {
    }
};