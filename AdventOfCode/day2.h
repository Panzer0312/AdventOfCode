#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<sstream>
#include "usefullStuff.h"

using namespace std;
class day2 {
public:
	static int day2Execute();
	static std::vector<string> splitInput(string input, string delimiter);
	static int findCubeCount(string input, string color);
	static int splitGamePhase(string game, string delimiter);
};