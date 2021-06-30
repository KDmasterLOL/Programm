void InitSDL(Uint32 flag)
{
    if (SDL_Init(flag) != 0)
        throw std::runtime_error(std::string("SDL cannot init:") + std::string(SDL_GetError()));
}
void InitImage()
{
    int image_flag = IMG_INIT_PNG;
    if (IMG_Init(image_flag) != image_flag)
    throw std::runtime_error(std::string("IMG not init")+std::string(IMG_GetError()));
}