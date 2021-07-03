#pragma once
#include <Commands.hpp>

class SDLWindowSDLGame_1 : public SDL_class
{
protected:
enum ID_TEXTURES{
    ID_TEXTURE_HELLO_TABLE,
};
    void InitData()
    {
        text.insert(std::pair<int,TextureObject>(ID_TEXTURE_HELLO_TABLE,TextureObject{"res/Hello.png"}));
        for(auto &text_obj:text){
        SDL_Texture* buffer = InitTextureFromSurface(InitSurfaceFromFile(text_obj.second.path,window_surface),render);
        text[text_obj.first].texture = buffer;
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
    }
};