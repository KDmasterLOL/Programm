#pragma once
#include "Command.hpp"
class CommandData : public Command
{
private:
    std::fstream file;
    std::ofstream write_file;
    std::fstream latest_files;
    std::vector<std::string> latest_files_names;
    std::string file_latest_file_name = "latest_files.txt";
    std::string file_text;
    int file_size;

public:
    CommandData() : Command("Command database")
    {
    }
    ~CommandData()
    {
        file.close();
        latest_files.close();
    }
    bool OpenLatestFile()
    {

        latest_files.open(file_latest_file_name, std::fstream::ate | std::fstream::out | std::fstream::in);
        if (!latest_files.is_open())
        {
            write_file.open(file_latest_file_name);
            write_file.close();
            latest_files.open(file_latest_file_name);
        }
        return latest_files.is_open();
    }
    bool ReadLatestFile()
    {
        ReadFile(file_latest_file_name, file_text);
        if (!file_text.empty())
            return true;
        else
            return false;
    }
    bool FoundLatestFiles()
    {
        std::string buffer;
        for (int letter = 0; letter < file_text.size(); letter++)
        {
            if (file_text[letter] != ';')
                buffer.push_back(file_text[letter]);
            else
            {
                latest_files_names.push_back(buffer);
                buffer.clear();
            }
        }
        if (latest_files_names.empty())
            return false;
        else
            return true;
    }
    void ShownLatestFiles()
    {
        for (int index = 0; index < latest_files_names.size(); index++)
        {
            std::cout << index << '.' << latest_files_names.at(index) << std::endl;
        }
    }
    void EnterUser()
    {
        std::cout << "Enter path to file";
        if (!latest_files_names.empty())
            std::cout << " or chouse latest file path";
            cout<<"(command \"exit\" to exit)"<<endl;
        std::string path;
        int number = 0;
        file.exceptions(std::fstream::failbit | std::fstream::badbit);
        while (std::cin >> path)
        {
            try
            {
                if (!path.empty())
                {
                    if(path == "exit")break;
                    else if (path[0] >= 48 && path[0] <= 57)
                    {
                        number = atoi(path.data());
                        if (latest_files_names.size() >= number)
                        {
                            file.open(latest_files_names.at(number));
                            break;
                        }
                    }
                    else
                    {
                        file.open(path.c_str());
                        break;
                    }
                }
            }
            catch (std::fstream::failure exc)
            {
                cerr << exc.what() << endl;
                std::cout << "Enter again" << std::endl;
                continue;
            }
        }
    }
    void Run()
    {
        if (OpenLatestFile())
        {
            if (ReadLatestFile())
            {
                if (FoundLatestFiles())
                    ShownLatestFiles();
                else
                    std::cout << "not found latest files" << std::endl;
            }
            else
                std::cout << "latest files now written" << std::endl;
        }
        else
            std::cout << "latest files not open" << std::endl;
        EnterUser();
    }
};