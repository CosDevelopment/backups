#ifndef QLOG_HPP
#define QLOG_HPP
#include "Common.hpp"

namespace EzyC
{

class QLog
{
  public:
    static void StreamErr(char *filename)
    {
        std::cout << rang::fgB::red << "FAILED TO OPEN FILE: " << filename << " ! \n"
                  << rang::style::reset;
    }
    static void StreamSuc(char *filename)
    {
        std::cout << rang::fgB::cyan << "Successfully reading file: " << filename << " ! \n"
                  << rang::style::reset;
    }
    static void LogFilesContents(std::ifstream &file, bool (*callback)(std::string))
    {
        std::string line;

        while (std::getline(file, line))
        {
            std::cout << rang::fg::blue << line << "\n";
            if (callback(line))
            {
                break;
            }
        }
    }
    static void LogTokenizedFileContents(std::vector<std::vector<std::string>> set, bool (*callback)(std::string))
    {
        for (auto line : set)
        {
            std::cout << "\n";
            for (auto tokens : line)
            {
                std::cout << rang::fgB::green << tokens;
            }
        }
        std::cout << "\n\n";
    }
};

} // namespace EzyC
#endif