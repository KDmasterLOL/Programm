#pragma once
#include "Utils/SDLUtils/UtilSDLHeaders.hpp" // SDL Headers
// Class
class SDL_class
{
protected:
    SDL_Window *window;
    SDL_Surface *window_surface;
    SDL_Renderer *render;
    map_texture textures;
    map_path_to_texture paths;
    map_keys keys;

public:
    SDL_class() {}
    ~SDL_class() {}

    virtual bool Init()
    {
        try
        {
            InitSDL();
            InitImage();
            InitWnd(&window);
            InitWndSurf(window, &window_surface);
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
    virtual void Draw() {}
    virtual void ProccesingKey() {}
    virtual void InitData() {}
    void InitTextureMapByPathMap()
    {
        for (auto path : paths)
        {
            SDL_Texture *buffer = InitTextureFromSurface(
                InitSurfaceFromFile(path.second, window_surface),
                render);
            textures.insert(pair_texture(path.first, buffer));
        }
    }
    virtual void QuitSDL()
    {
        SDL_DestroyWindow(window);
        window_surface = nullptr;
        for (auto &texture : textures)
        {
            if (texture.second != nullptr)
            {
                SDL_DestroyTexture(texture.second);
                texture.second = nullptr;
            }
        }
        SDL_DestroyRenderer(render);
        keys.clear();
        textures.clear();
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