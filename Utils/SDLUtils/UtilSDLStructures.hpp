#pragma once 
#include"Utils/SDLUtils/UtilSDLHeaders.hpp" // SDL Headers
// Structures SDL Util
struct GameObjectStruct{
    SDL_Rect rect;
    std::string path_to_texture;
    ID_GAME_OBJECTS id;
    GameObjectClass* game_object = nullptr;
}; // Rect,GameObjectClass,string,Texture