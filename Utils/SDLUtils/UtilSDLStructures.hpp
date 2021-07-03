#pragma once 
#include"Utils/SDLUtils/UtilSDLHeaders.hpp" // SDL Headers
// Structures SDL Util
struct TextureObject
{
    string path;
    SDL_Texture *texture = nullptr;
};

