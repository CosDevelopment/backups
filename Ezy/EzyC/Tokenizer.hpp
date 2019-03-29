#ifndef TOKENIZER_HPP // include guard
#define TOKENIZER_HPP
#include "Common.hpp"
#include <regex>
#include <cstring>
namespace EzyC
{
#define endFile [](std::string e) -> bool {if (e == "end") return true;else false; }
class Tokenizer
{
  private:
    static std::vector<std::string> fileToVec(std::ifstream &file, bool (*callback)(std::string))
    {
        std::string line;
        std::vector<std::string> vec;
        while (std::getline(file, line))
        {
            vec.push_back(line);
            if (callback(line))
            {
                break;
            }
        }
        return vec;
    }

  public:
    static void start(char *filename)
    {
        //Varaibles
        std::ifstream progfile;
        std::string line;
        bool EndOfProgram = false;
        progfile.open(filename);

        std::cout << rang::fgB::yellow << "Initaliziation started" << std::endl;
        std::cout << rang::fg::yellow << "opening file: " << rang::fgB::magenta << filename << std::endl;

        if (!progfile.is_open())
        {
            QLog::StreamErr(filename);
            return;
        }
        else
        {
            QLog::StreamSuc(filename);
            // QLog::LogFilesContents(progfile, endFile);
            QLog::LogTokenizedFileContents(Tokenize(progfile), endFile);
        }
        progfile.close();
    }
    static std::vector<std::vector<std::string>> Tokenize(std::ifstream &file)
    {
        std::vector<std::string> lines = fileToVec(file, endFile);
        std::vector<std::string> tokens;
        std::vector<std::vector<std::string>> set;
        std::string generator;
        for (std::string line : lines)
        {
            for (char character : line)
            {
                if (character != ' ' && character != '=' && character != ',')
                {
                    generator += character;
                }
                else if (character == ' ' && generator == "")
                {
                    continue;
                }
                else if (character == '=')
                {
                    tokens.push_back(generator);
                    if (generator != "")
                    {
                        tokens.push_back(",");
                    }
                    tokens.push_back("=");
                    tokens.push_back(",");
                    generator = "";
                }
                else
                {
                    tokens.push_back(generator);
                    tokens.push_back(",");
                    generator = "";
                }
            }
            tokens.push_back(generator);
            generator = "";
            set.push_back(tokens);
            tokens.clear();
        }
        return set;
    };
};
} // namespace EzyC

#endif