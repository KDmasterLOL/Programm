#pragma once
#include "Command.hpp"

class CommandWindowOpenGL : public Command
{
private:
    enum ID_textures
    {
        ID_background,
        ID_table,

    };
    struct object
    {
        SDL_Surface *texture;
        SDL_Rect pos;
    };
    int16_t window_heigth = 600,
            window_width = 800;
    SDL_Surface *surface_screen;
    SDL_Window *window;
    std::map<SDL_Keycode, bool> keys;
    std::map<int, object> textures;
    SDL_GLContext gl_context;
    SDL_Rect rect_background = {0, 0, window_width, window_heigth};
    GLuint vbo;
    GLuint shader_programm;
    std::string shader_vs = "vertex_shader.vs", shader_fs = "fragment_shader.fs";
    std::vector<glm::vec3> vec = {{0, -1, 0}, {1, 1, 0}, {-1, 1, 0}};
    glm::mat4 mat = glm::mat4(1.0f);
    GLuint ScaleLocation, MatLocation;
    bool is_rotate = false, is_translate = false, is_repeat = false, is_scale = false;

public:
    CommandWindowOpenGL() : Command("Command WindowOpenGL") {}
    ~CommandWindowOpenGL() {}

    void SetAttrGL()
    {
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 6);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
    }
    bool InitGL()
    {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

        return true;
    }

    bool InitData()
    {
        MatLocation = glGetUniformLocation(shader_programm, "mat");
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, vec.size() * sizeof(glm::vec3), &vec.front(), GL_STATIC_DRAW);

        return true;
    }
    bool Init()
    {
        try
        {
            InitSDL(SDL_INIT_EVERYTHING);
            InitWnd(&window);
            SetAttrGL();
            InitContextGL(&gl_context, window);
            InitGLEW();
            InitGL();
            shader_programm = InitShader(shader_vs, shader_fs);
            InitData();
            return true;
        }
        catch (std::runtime_error exc)
        {
            std::cerr << exc.what() << std::endl;
            return false;
        }
    }
    void ShowKeyBind()
    {
        std::cout << "R - recover\n"
                  << "F - repeat\n"
                  << "A - translate\n"
                  << "W - rotate\n"
                  << "S - scale" << std::endl;
    }
    void RecoverDefaultSetting()
    {
        mat = glm::mat4(1.f);
        is_repeat = false;
        is_rotate = false;
        is_translate = false;
        is_scale = false;
    }
    void Draw()
    {

        SDL_FillRect(surface_screen, NULL, SDL_MapRGB(surface_screen->format, 0, 0, 0));
        SDL_BlitScaled(textures.at(ID_table).texture, NULL, surface_screen, &textures.at(ID_table).pos);
        SDL_UpdateWindowSurface(window);
        SDL_Delay(16);
    }
    void DrawGL()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        if (is_translate)
            mat = glm::translate(mat, glm::vec3(0.01f, 0.01f, 0.f));
        if (is_scale)
            mat = glm::scale(mat, glm::vec3(0.99f));

        glUniformMatrix4fv(MatLocation, 1, GL_TRUE, glm::value_ptr(mat));
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glDrawArrays(GL_TRIANGLES, 0, vec.size());

        glDisableVertexAttribArray(0);
        SDL_GL_SwapWindow(window);
        SDL_Delay(16);
    }
    void ProccesingKey()
    {
        if (GetKeyDownUp(SDLK_r))
            RecoverDefaultSetting();
        is_translate = GetKeyDownUp(SDLK_a);
        is_repeat = GetKeyDownUp(SDLK_f);
        is_scale = GetKeyDownUp(SDLK_s);
        is_rotate = GetKeyDownUp(SDLK_w);
    }
    void LoapSDL()
    {
        bool play = true;
        SDL_Event e;
        while (play)
        {

            while (SDL_PollEvent(&e) != 0)
            {
                switch (e.type)
                {
                case SDL_QUIT:
                    play = false;
                    break;
                case SDL_KEYDOWN:
                    KeyCheck(e.key.keysym.sym, true);
                    break;
                case SDL_KEYUP:
                    KeyCheck(e.key.keysym.sym, false);
                    break;
                default:
                    break;
                }
            }
            play = !GetKeyDownUp(SDLK_ESCAPE);
            ProccesingKey();
            // Draw();
            DrawGL();
        }
    }
    bool GetKeyDownUp(int key)
    {
        try
        {
            return keys.at(key);
        }
        catch (std::out_of_range)
        {
            return false;
        }
    }
    void KeyCheck(SDL_Keycode key, bool down_up)
    {
        try
        {
            keys.at(key) = down_up;
        }
        catch (std::out_of_range exc)
        {
            keys.insert(std::pair<SDL_Keycode, bool>(key, down_up));
        }
    }
    void Quit()
    {
        SDL_DestroyWindow(window);
        surface_screen = nullptr;
        for (auto &surf : textures)
        {
            if (surf.second.texture != nullptr)
            {
                SDL_FreeSurface(surf.second.texture);
                surf.second.texture = nullptr;
            }
        }
        keys.clear();
        textures.clear();
        IMG_Quit();
        SDL_Quit();
    }
    void Run()
    {
        if (!Init())
            return;
        ShowKeyBind();
        LoapSDL();
        Quit();
    }
};
