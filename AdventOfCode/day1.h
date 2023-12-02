#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<sstream>
#include "usefullStuff.h"
using namespace std;

class day1 {
public:
	static string replace_all(string s, std::string toReplace, std::string replaceWith);
	static string convertToNumbers(string s);
	static int findFigures(string input);
	static void day1Execute();
};