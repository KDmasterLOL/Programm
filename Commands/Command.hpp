#pragma once
#include <iostream>
#include <sqlite3.h>
#include <string_view>
#include <fstream>
#include <cstdlib>
#include <exception>
#include <vector>
#include <map>
#include "Utils/opengl.hpp"
#include "Utils/InitSDL.hpp"
class Command
{
private:
    std::string command_name;

public:
    Command(std::string command = "command") : command_name(command)
    {
    }
    void ShowCommandName()
    {
        std::cout << "Command \"" << command_name << "\"" << std::endl;
    }
    virtual void Run()
    {
    }
};
