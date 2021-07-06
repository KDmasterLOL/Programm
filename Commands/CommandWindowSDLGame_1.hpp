#pragma once
#include <Commands.hpp>
class SDLWindowSDLGame_1 : public SDL_class
{
protected:
    enum ID_OBJECTS
    {
        // ID_OBJECT_
        ID_OBJECT_Background,
    };

    void InitGameObjectsStruct()
    {
        SDL_Rect buff_rc = SDL_Rect{0, 0, window_width, window_height};
        std::string buff_path = "res/Hello.png";
        game_objects_struct.insert(pair_game_objects_struct(
            ID_OBJECT_Background,
            GameObjectStruct{buff_rc, buff_path, ID_GAME_OBJECTS::ID_Background}));
        
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