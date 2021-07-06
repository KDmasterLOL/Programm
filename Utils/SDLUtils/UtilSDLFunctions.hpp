#pragma once
// Include
#include "Utils/SDLUtils/UtilSDLHeaders.hpp"
// Functions
void InitSDL(Uint32 flag = SDL_INIT_EVERYTHING)
{
    if (SDL_Init(flag) != 0)
        throw std::runtime_error(std::string("SDL cannot init:") + std::string(SDL_GetError()));
}
void InitImage(int image_flag = IMG_INIT_PNG)
{
    if (IMG_Init(image_flag) != image_flag)
        throw std::runtime_error(std::string("IMG not init:") + std::string(IMG_GetError()));
}
void InitWnd(SDL_Window **window, int w = 800, int h = 600,
             std::string name = "Window",
             Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL,
             int x = SDL_WINDOWPOS_UNDEFINED, int y = SDL_WINDOWPOS_UNDEFINED)
{
    *window = SDL_CreateWindow(name.c_str(), x, y, w, h, flags);
    if (*window == nullptr)
        throw std::runtime_error("Window don't created:" + std::string(SDL_GetError()));
}
void InitWndSurf(SDL_Window *window, SDL_Surface **surface)
{
    *surface = SDL_GetWindowSurface(window);
    if (*surface == nullptr)
        throw std::runtime_error("Surface screen not init:" + std::string(SDL_GetError()));
}
void InitRenderer(SDL_Window *window, SDL_Renderer **render, Uint32 flag = SDL_RENDERER_ACCELERATED)
{
    *render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (*render == NULL)
        throw std::runtime_error("Renderer not init:" + std::string(SDL_GetError()));
    SDL_SetRenderDrawColor(*render, 0, 0, 0, 0);
}
void InitContextGL(SDL_GLContext *gl_context, SDL_Window *window)
{
    *gl_context = SDL_GL_CreateContext(window);
    if (*gl_context == nullptr)
        throw std::runtime_error("Context GL not init:" + std::string(SDL_GetError()));
}
SDL_Surface *InitSurfaceFromFile(std::string path, SDL_Surface *surface_screen = nullptr)
{
    SDL_Surface *buffer_image = nullptr, *buffer_texture = nullptr;
    buffer_texture = IMG_Load(path.c_str());
    if (buffer_texture == nullptr)
        throw std::runtime_error(path + " not createn" + std::string(IMG_GetError()));
    else if(surface_screen != nullptr)
        buffer_image = SDL_ConvertSurface(buffer_texture, surface_screen->format, 0);
    if (buffer_image != nullptr)
    {
        SDL_FreeSurface(buffer_texture);
        return buffer_image;
    }
    else
    {
        return buffer_texture;
    }
}
SDL_Texture *InitTextureFromSurface(SDL_Surface *surface, SDL_Renderer *renderer)
{
    SDL_Texture *texture;
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}
SDL_Texture *InitTextureFromPath(std::string path,SDL_Renderer *renderer, SDL_Surface *surface_screen = nullptr)
{
    SDL_Surface *buff_surface = InitSurfaceFromFile(path.c_str(), surface_screen);
    return InitTextureFromSurface(buff_surface, renderer);
}
bool GetKeyDownUp(map_keys &keys, int key)
{
    try
    {
        return keys.at(key);
    }
    catch (std::out_of_range)
    {
        return false;
    }
}
void KeyCheck(map_keys &keys, SDL_Keycode key, bool down_up)
{
    try
    {
        keys.at(key) = down_up;
    }
    catch (std::out_of_range exc)
    {
        keys.insert(std::pair<SDL_Keycode, bool>(key, down_up));
    }
}
