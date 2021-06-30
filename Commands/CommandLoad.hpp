#pragma once
#include "Command.hpp"
class CommandLoad : public Command
{
private:
    int load_line = 10;
    int pos_point = 0;
    void DrawLine()
    {
        for (int i = 0; i < load_line; i++)
        {
            if (pos_point == i)
                std::cout << "-";
            else
                std::cout << "=";
        }
        std::cout << std::endl;
    }

public:
    CommandLoad() : Command("Command load")
    {
    }
    void Run()
    {
        clock_t last_time = clock(), now;
        DrawLine();
        while (pos_point != load_line)
        {
            now = clock();
            if (now - last_time > (clock_t)1000)
            {
                system("clear");
                last_time = clock();
                pos_point += 1;
                DrawLine();
            }
        }
    }
};