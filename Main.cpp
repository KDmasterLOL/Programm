#include "Commands.hpp"
int main()
{
    // Vector of commands
    std::vector<Command *> commands;
    // Init vector
    // commands.push_back();
    commands.push_back(new CommandHello);
    commands.push_back(new CommandLoad);
    commands.push_back(new CommandData);
    commands.push_back(new CommandWindow);
    CommandChouse chouse(commands);
    chouse.Run();
}