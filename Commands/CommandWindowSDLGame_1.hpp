#pragma once
#include <Commands.hpp>

class SDLWindowSDLGame_1 : public SDL_class
{
protected:
    enum ID_TEXTURES
    {
        // ID_TEXTURE_
        ID_TEXTURE_HelloTable,
    };
    enum ID_OBJECTS{
        // ID_OBJECT_
        ID_OBJECT_Background,
    };
    void InitData()
    {
        paths.insert(pair_path_to_texture(ID_TEXTURE_HelloTable, "res/Hello.png"));
        InitTextureMapByPathMap();2
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
    }
};