// Tool to do the job of "dd" on Windows to create ram and rom files of target binaries.

#include <cstdio>
#include <fstream>
#include <vector>
#include <string>

std::string GetArg(std::string key, const std::vector<std::string> &args)
{
    for (const auto &arg : args)
    {
        if (arg.compare(0, key.size(), key) == 0)
            return arg.substr(key.size() + 1);
    }

    return "";
}

int StrToInt(const std::string &str)
{
    try
    {
        return std::stoi(str);
    }
    catch (const std::exception &e)
    {
        return -1;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        printf("Invalid number of arguments\n");
        return 1;
    }

    std::vector<std::string> args;
    for (int i = 0; i < argc; i++)
    {
        args.push_back(argv[i]);
    }

    int count = StrToInt(GetArg("count", args));
    int skip = StrToInt(GetArg("skip", args));
    std::string inFile = GetArg("if", args);
    std::string outFile = GetArg("of", args);

    std::ifstream in(inFile, std::ios::binary);
    if (!in)
    {
        printf("Cannot open input file\n");
        return 1;
    }

    std::ofstream out(outFile, std::ios::binary);
    if (!out)
    {
        printf("Cannot open output file\n");
        return 1;
    }

    if (skip != -1)
    {
        in.seekg(skip);
    }

    if (count != -1)
    {
        std::vector<char> buf(count, 0);
        in.read(buf.data(), count);
        out.write(buf.data(), count);
    }
    else
    {
        out << in.rdbuf();
    }

    return 0;
}