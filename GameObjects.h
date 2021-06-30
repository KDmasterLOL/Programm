#include <SDL2/SDL.h>
#include <map>
class Object
{
protected:
    SDL_Rect rect;
    SDL_Surface *texture;
    Object(SDL_Rect rc, SDL_Surface *surf) : rect(rc), texture(surf) {}
    virtual void Move() {}
};
SDL_Rect operator-(SDL_Rect rc, float f)
{
    rc.h -= f;
    rc.w -= f;
    rc.x -= f;
    rc.y -= f;
}
class Player : public Object
{
    float speed;

public:
    Player(SDL_Rect rc, SDL_Surface *surf, float sp = 1) : Object(rc, surf), speed(sp) {}
    void Move(std::map<SDL_Keycode, bool> keys)
    {
        try
        {
            if (keys.at(SDLK_w))
            {
            }
            else if (keys.at(SDLK_s))
            {
            }
            else if (keys.at(SDLK_a))
            {
            }
            else if (keys.at(SDLK_d))
            {
            }
        }
        catch (std::out_of_range exc)
        {
        }
    }
};