#pragma once
#include "Utils/SDLUtils/UtilSDLHeaders.hpp" // SDL Headers
// Class
class SDL_class
{
protected:
    // Variables of class
    SDL_Window *window;
    SDL_Renderer *render;
    SDL_Surface *window_surface;
    int window_height = 600, window_width = 800;
    map_game_objects_struct game_objects_struct;
    map_game_objects_class game_objects_class;
    map_keys keys;
    // Function of class
    virtual bool Init()
    {
        try
        {
            InitSDL();
            InitImage();
            InitWnd(&window, window_width, window_height);
            InitRenderer(window, &render);
            InitData();
            return true;
        }
        catch (runtime_error exc)
        {
            std::cerr << exc.what() << std::endl;
            return false;
        }
    }
    virtual void InitGameObjectsStruct() {}
    virtual void InitData()
    {
        InitGameObjectsStruct();
        InitGameObjectsClass();
    }
    void InitGameObjectsClass()
    {
        for (auto game_object : game_objects_struct)
        {
            game_objects_class.insert(pair_game_objects_class(game_object.first, MakeGameObjectClass(game_object.second)));
        }
        game_objects_struct.clear();
    }

    virtual void LoapSDL()
    {
        bool play = true;
        SDL_Event e;
        while (play)
        {

            while (SDL_PollEvent(&e) != 0)
            {
                switch (e.type)
                {
                case SDL_QUIT:
                    play = false;
                    break;
                case SDL_KEYDOWN:
                    KeyCheck(keys, e.key.keysym.sym, true);
                    break;
                case SDL_KEYUP:
                    KeyCheck(keys, e.key.keysym.sym, false);
                    break;
                default:
                    break;
                }
            }
            play = !GetKeyDownUp(keys, SDLK_ESCAPE);
            ProccesingKey();
            Draw();
        }
    }
    virtual void Draw()
    {
        SDL_RenderClear(render);
        DrawGameObjectsClass();
        SDL_RenderPresent(render);
    }
    void DrawGameObjectsClass()
    {
        for (auto game_object : game_objects_class)
        {
            SDL_RenderCopy(render, game_object.second->GetTexture(), nullptr, game_object.second->GetRect());
        }
    }
    virtual void ProccesingKey() {}
    virtual void QuitSDL()
    {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(render);
        for (auto game_object : game_objects_class)
        {
            game_object.second->~GameObjectClass();
        }
        game_objects_class.clear();
        keys.clear();
        IMG_Quit();
        SDL_Quit();
    }
    GameObjectClass *MakeGameObjectClass(GameObjectStruct &game_object)
    {
        SDL_Texture *buffer_texture = InitTextureFromPath(game_object.path_to_texture, render);
        switch (game_object.id)
        {
        case ID_GAME_OBJECTS::ID_Background:
            return new Background(buffer_texture, game_object.rect, SDL_Rect{0, 0, window_width, window_height}, game_objects_class);
        default:
            return nullptr;
        }
    }
};
