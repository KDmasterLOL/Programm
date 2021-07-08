#pragma once
// Include
#include <functional>
#include <vector>
#include <iostream>
#include <string_view>
#include <fstream>
#include <cstdlib>
#include <exception>
#include <map>
// Using
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;
using std::string;
using std::vector;
using namespace std::placeholders;
// Fuctions
void ReadFile(std::string file_name, std::string &out_file)
{
    std::ifstream file(file_name.c_str());

    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            out_file.append(line);
            out_file.append("\n");
        }
        file.close();
    }
    else
        throw std::runtime_error("file not open:" + file_name);
}