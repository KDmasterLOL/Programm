#pragma once
#include "Command.hpp"
class CommandExit : public Command
{
private:
    bool *play = nullptr;

public:
    CommandExit() : Command("Command Exit")
    {
    }
    CommandExit(bool &play) : Command("Command Exit")
    {
        this->play = &play;
    }
    void Run()
    {
        if (play == nullptr)
            exit(EXIT_SUCCESS);
        else
            *play = false;
    }
};