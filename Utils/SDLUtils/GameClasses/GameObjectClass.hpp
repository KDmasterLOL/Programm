#pragma once
#include "Utils/SDLUtils/UtilSDLHeaders.hpp" // SDL Headers
// Class

class GameObjectClass
{
protected:
    ID_GAME_OBJECTS id_object;
    SDL_Texture *texture;
    SDL_Rect default_window_rect;
    SDL_FRect rect;
    map_game_objects_class &game_objects;
    GameObjectClass(SDL_Texture *texture, SDL_FRect rect, SDL_Rect default_window_rect,
                    map_game_objects_class &game_objects) : game_objects(game_objects)
    {
        this->texture = texture;
        this->rect = rect;
        this->default_window_rect = default_window_rect;
    }

    virtual void Move() {}
    virtual void CheckObjects() {}

public:
    virtual void Update() {}
    virtual ~GameObjectClass()
    {
        SDL_DestroyTexture(texture);
    }
    virtual SDL_Texture *GetTexture()
    {
        return texture;
    }
    virtual SDL_FRect* GetRect()
    {
        return &rect;
    }
};