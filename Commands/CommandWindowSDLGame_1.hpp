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
    void InitData()
    {
        SDL_Rect buff_rc = SDL_Rect{0, 0, window_width, window_height};
        std::string buff_path = "res/Hello.png";
        game_objects.insert(pair_game_objects(
            ID_OBJECT_Background,
            GameObjectStruct{buff_rc, buff_path}));
    }
    void InitObjects()
    {
        
    }
    void Draw()
    {
        SDL_RenderClear(render);
        SDL_RenderPresent(render);
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