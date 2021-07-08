#pragma once
#include <Commands.hpp>
class SDLWindowSDLGame_1 : public SDL_class
{
protected:
    enum ID_OBJECTS
    {
        // ID_OBJECT_
        ID_OBJECT_Background,
        ID_OBJECT_Player,
    };

    void InitGameObjectsStruct()
    {
        vector<GameObjectStruct> buff_game_objects;
        // buff_game_objects.push_back({});
        buff_game_objects.push_back({SDL_FRect{0, 0, (float)window_width, (float)window_height}, "res/Hello.png", ID_GAME_OBJECTS::ID_Background, ID_OBJECT_Background});
        buff_game_objects.push_back({SDL_FRect{0, 0, 100, 100}, "res/Hello.png", ID_GAME_OBJECTS::ID_Player, ID_OBJECT_Player});
        for (auto game_object : buff_game_objects)
        {
            AddGameObjectStructToMap(game_object);
        }
    }
};
class CommandWindowSDLGame_1 : public Command, public SDLWindowSDLGame_1
{
private:
public:
    CommandWindowSDLGame_1() : Command("Command CommandWindowSDLGame_1") {}
    ~CommandWindowSDLGame_1() {}

    void ProccesingKey()
    {
    }

    void Run()
    {
        if (!Init())
            return;
        LoapSDL();
        QuitSDL();
    }
};