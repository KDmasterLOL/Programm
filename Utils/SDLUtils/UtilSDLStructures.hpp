#pragma once 
#include"Utils/SDLUtils/UtilSDLHeaders.hpp" // SDL Headers
// Structures SDL Util
struct GameObjectStruct{
    SDL_FRect rect;
    std::string path_to_texture;
    ID_GAME_OBJECTS id_game_object;
    int id_object;
}; // Rect,GameObjectClass,string,Texture
