#include "usefullStuff.h"

vector<string> usefullStuff::readInputEachLine(string file) {
    string line;
    ifstream input1(file);
    vector<string> data;
    while (getline(input1, line))
    {
        data.push_back(line);
    }
    return data;
};
