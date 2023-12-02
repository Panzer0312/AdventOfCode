#include "usefullStuff.h"

std::vector<string> usefullStuff::readInputEachLine(string file) {
    string line;
    ifstream input1(file);
    std::vector<string> data;
    while (getline(input1, line))
    {
        data.push_back(line);
    }
    return data;
};
