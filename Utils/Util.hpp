#pragma once
#include"Commands/Command.hpp"
#include<vector>
void ReadFile(std::string file_name, std::string &out_file)
{
    std::ifstream f(file_name.c_str());

    if (f.is_open())
    {
        std::string line;
        while (getline(f, line))
        {
            out_file.append(line);
            out_file.append("\n");
        }
        f.close();
    }
    else
        throw std::runtime_error("file not open:" + file_name);
}
// void UserChouseFromCommandVect()
// {
//     std::vector<Command*> command_vector;
//     for (int command = 0; command < command_vector.size(); command++)
//     {
//         std::cout << command << ".";
//         command_vector[command]->ShowCommandName();
//     }
//     std::cin.exceptions(std::ios_base::badbit | std::ios_base::failbit);
//     while (true)
//     {
//         std::cout << "Chouse command - " << std::endl;
//         int command;
//         try
//         {
//             std::cin >> command;
//             command_vector.at(command)
//                 ->Run();
//         }
//         catch (std::ios::failure exc)
//         {
//             std::cerr << "not actual enter, try again enter number" << std::endl;
//             std::cin.clear();
//             std::cin.ignore(32767, '\n');
//         }
//         catch (std::out_of_range exc)
//         {
//             std::cout << "enter again number of list" << std::endl;
//         }
//     }
// }