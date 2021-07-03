#pragma once
// Include
#include "Utils/Util.hpp"
#include "Utils/UtilOpengl.hpp"
#include "Utils/UtilSDL.hpp"
// Class Command for Inheritated
class Command
{
private:
    std::string command_name;

protected:
    Command(std::string command = "command") : command_name(command)
    {
    }

public:
    void ShowCommandName()
    {
        std::cout << "Command \"" << command_name << "\"" << std::endl;
    }

    virtual void Run()
    {
    }
};
