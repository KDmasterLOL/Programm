#pragma once
#include "Utils/SDLUtils/UtilSDLHeaders.hpp" // SDL Headers
// Class
class GameObject{
    protected:
    SDL_Texture* texture;
    SDL_Rect rect;
    GameObject(SDL_Texture* txtr,SDL_Rect rc):texture(txtr),rect(rc){}
};