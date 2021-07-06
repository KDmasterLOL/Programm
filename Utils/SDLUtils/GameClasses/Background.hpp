#pragma once
#include "GameObjectClass.hpp"
// Class
class Background : public GameObjectClass // Texture,Rect,window_rect,game_objects
{
private:
public:
    Background(SDL_Texture *texture, SDL_Rect rect, SDL_Rect window_rect,
               map_game_objects_class &game_objects)
        : GameObjectClass(texture, rect, window_rect, game_objects)
    {
        id_object = ID_GAME_OBJECTS::ID_Background;
    }
};