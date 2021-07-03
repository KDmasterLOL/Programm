#pragma once
// Include
#include<functional>
#include<vector>
#include <iostream>
#include <sqlite3.h>
#include <string_view>
#include <fstream>
#include <cstdlib>
#include <exception>
#include <map>
// Using
using std::cout;
using std::endl;
using std::runtime_error;
using std::string;
using namespace std::placeholders;
// Fuctions
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