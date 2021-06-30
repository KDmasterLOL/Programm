#pragma once
#include <GL/glew.h>
#include <Utils/Util.hpp>
void InitGLEW()
{
    GLenum err = glewInit();
    if (err == GLEW_OK)
    {
        std::cout << "GL version:" << glGetString(GL_VERSION) << std::endl;
    }
    else
        throw std::runtime_error("GLEW not init:" + std::string((char *)glewGetErrorString(err)));
}
void CreateShader(GLuint shader_programm, std::string shader_text, GLenum shader_type)
{
    GLuint shader_obj = glCreateShader(shader_type);
    if (shader_obj == 0)
        throw std::runtime_error("Shader not createn " + shader_type);
    const GLchar *p[1];
    p[0] = shader_text.c_str();
    GLint Lengths[1];
    Lengths[0] = strlen(shader_text.c_str());
    glShaderSource(shader_obj, 1, p, Lengths);
    glCompileShader(shader_obj);
    GLint success;
    glGetShaderiv(shader_obj, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        GLchar InfoLog[124];
        glGetShaderInfoLog(shader_obj, 124, NULL, InfoLog);
        char err_msg[1024];
        sprintf(err_msg, "Error compiling shader type %d: '%s'\n", shader_type, InfoLog);
        throw std::runtime_error(err_msg);
    }

    glAttachShader(shader_programm, shader_obj);
}
unsigned int InitShader(std::string shader_path_vs, std::string shader_path_fs)
{
    GLuint shader_programm = glCreateProgram();
    if (shader_programm == 0)
        throw std::runtime_error("Error creating shader programm");

    std::string vs, fs;

    ReadFile(shader_path_vs, vs);
    ReadFile(shader_path_fs, fs);

    CreateShader(shader_programm, vs.c_str(), GL_VERTEX_SHADER);
    CreateShader(shader_programm, fs.c_str(), GL_FRAGMENT_SHADER);

    GLint Success = 0;
    GLchar ErrorLog[1024] = {0};

    glLinkProgram(shader_programm);
    glGetProgramiv(shader_programm, GL_LINK_STATUS, &Success);
    if (Success == 0)
    {
        glGetProgramInfoLog(shader_programm, sizeof(ErrorLog), NULL, ErrorLog);
        fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
        exit(1);
    }

    glValidateProgram(shader_programm);
    glGetProgramiv(shader_programm, GL_VALIDATE_STATUS, &Success);
    if (!Success)
    {
        glGetProgramInfoLog(shader_programm, sizeof(ErrorLog), NULL, ErrorLog);
        fprintf(stderr, "Invalid shader program: '%s'\n", ErrorLog);
        exit(1);
    }

    glUseProgram(shader_programm);


    return shader_programm;
}
