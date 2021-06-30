#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdexcept>
#include <string>
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
void InitWnd(SDL_Window **window, std::string name = "Window",
             Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL,
             int w = 800, int h = 600,
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
void InitContextGL(SDL_GLContext *gl_context, SDL_Window* window)
{
    *gl_context = SDL_GL_CreateContext(window);
    if (*gl_context == nullptr)
        throw std::runtime_error("Context GL not init:" + std::string(SDL_GetError()));
}
SDL_Surface *InitSurfaceFromFile(std::string path, SDL_Surface *surface_screen)
{

    SDL_Surface *buffer_image, *buffer_texture;
    buffer_texture = IMG_Load(path.c_str());
    if (buffer_texture == nullptr)
        throw std::runtime_error(path + " not createn");
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