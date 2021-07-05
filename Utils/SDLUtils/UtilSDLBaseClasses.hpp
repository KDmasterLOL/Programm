#pragma once
#include "Utils/SDLUtils/UtilSDLHeaders.hpp" // SDL Headers
// Class
class SDL_class
{
protected:
    // Variables of class
    SDL_Window *window;
    SDL_Surface *window_surface;
    SDL_Renderer *render;
    int window_height = 600,window_width = 800;
    map_game_objects game_objects;
    map_keys keys;
    // Function of class
    virtual bool Init()
    {
        try
        {
            InitSDL();
            InitImage();
            InitWnd(&window,window_width,window_height);
            InitWndSurf(window, &window_surface);
            InitRenderer(window, &render);
            InitData();
            InitObjects();
            return true;
        }
        catch (runtime_error exc)
        {
            std::cerr << exc.what() << std::endl;
            return false;
        }
    }
    virtual void Draw() {}
    virtual void ProccesingKey() {}
    virtual void InitData() {}
    virtual void InitObjects() {}

    virtual void QuitSDL()
    {
        SDL_DestroyWindow(window);
        window_surface = nullptr;

        SDL_DestroyRenderer(render);
        keys.clear();
        IMG_Quit();
        SDL_Quit();
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
};