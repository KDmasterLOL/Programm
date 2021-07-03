#pragma once
#include"GameObject.hpp"
class Player:public GameObject{
    Player(SDL_Texture* texture,SDL_Rect rect):GameObject(texture,rect){
        
    }
};