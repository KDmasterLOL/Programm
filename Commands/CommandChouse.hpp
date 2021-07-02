#pragma once
// Include
#include "Commands.hpp"
// Type alises
using vector_command = std::vector<Command*>;

class CommandChouse : public Command
{
private:
    std::vector<Command *> commands;
    bool play = true;

public:
    CommandChouse(vector_command commands) : Command("Command Chouse")
    {
        this->commands = commands;
        this->commands.push_back(new CommandExit(play));
    }
    void Run()
    {

        std::cin.exceptions(std::ios_base::badbit | std::ios_base::failbit);
        while (play)
        {
            for (int comm = 0; comm < commands.size(); comm++)
            {
                std::cout << comm << ".";
                commands[comm]->ShowCommandName();
            }
            std::cout << "Chouse command - ";
            int comm;

            try
            {
                std::cin >> comm;
#ifdef linux
                system("clear");
#else
                system("cls");
#endif
                commands.at(comm)
                    ->Run();
            }
            catch (std::ios::failure exc)
            {
                std::cerr << "not actual enter, try again enter number" << std::endl;
                std::cin.clear();
                std::cin.ignore(32767, '\n');
            }
            catch (std::out_of_range exc)
            {
                std::cout << "enter again number of list" << std::endl;
            }
        }
    }
};