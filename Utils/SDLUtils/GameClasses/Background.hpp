#pragma once
#include"GameObject.hpp"
class Background:public GameObject{
    Background(SDL_Texture* texture,SDL_Rect rect):GameObject(texture,rect){
        
    }
};