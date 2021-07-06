#pragma once
// Include
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Utils/Util.hpp"
#include "Utils/SDLUtils/GameIDObjects.hpp"
#include "Utils/SDLUtils/UtilSDLStructures.hpp"
// Declaration
class GameObjectClass;
// Type alias
using map_game_objects_struct = std::map<int,GameObjectStruct>;
using pair_game_objects_struct = std::pair<int,GameObjectStruct>;
using map_game_objects_class = std::map<int,GameObjectClass*>;
using pair_game_objects_class = std::pair<int,GameObjectClass*>;
using map_keys = std::map<SDL_Keycode, bool>;
using map_surface = std::map<int, SDL_Surface *>;
using map_texture = std::map<int, SDL_Texture *>;
using map_path_to_texture = std::map<int,string>;
using pair_path_to_texture = std::pair<int,string>;
using pair_texture = std::pair<int, SDL_Texture *>;
// Include
#include "Utils/SDLUtils/GameClasses/Player.hpp"
#include "Utils/SDLUtils/GameClasses/Block.hpp"
#include "Utils/SDLUtils/GameClasses/Background.hpp"
#include "Utils/SDLUtils/UtilSDLFunctions.hpp"
