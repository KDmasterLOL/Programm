#pragma once
// Include
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Utils/Util.hpp"
#include "Utils/SDLUtils/UtilSDLStructures.hpp"
// Type alias
using map_keys = std::map<SDL_Keycode, bool>;
using map_surface = std::map<int, SDL_Surface *>;
using map_texture = std::map<int, SDL_Texture *>;
using pair_texture = std::pair<int, SDL_Texture *>;
using map_texture_objects = std::map<int, TextureObject>;
// Include
#include "Utils/SDLUtils/UtilSDLFunctions.hpp"
