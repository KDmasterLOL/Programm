#pragma once
#include "Command.hpp"
class CommandHello : public Command
{
private:
public:
    CommandHello() : Command("Command Hello")
    {
    }
    void Run()
    {
        std::cout << "Hello" << std::endl;
    }
};