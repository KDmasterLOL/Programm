#pragma once
#include "Commands.hpp"
class CommandWindow : public Command
{
private:
    // Vector of commands
    std::vector<Command *> commands;

public:
    CommandWindow() : Command("Command Window")
    {
        // Init vector
        // commands.push_back();
        commands.push_back(new CommandWindowOpenGL);
        commands.push_back(new CommandWindowSDLGame_1);
    }
    void Run()
    {
        CommandChouse chouse(commands);
        chouse.Run();
    }
};
