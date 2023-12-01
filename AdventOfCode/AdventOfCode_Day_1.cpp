// AdventOfCode.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<sstream>
using namespace std;

string replace_all(string s,std::string toReplace,std::string replaceWith
) {
    string newString = s;
    int pos = 0;
    while (pos >= 0) {
        pos = newString.find(toReplace);
        if (pos >= 0) {
            //Leave front and back so Twone can get replaced to 21
            string newRepl = toReplace.front() + replaceWith + toReplace.back();
            newString.replace(pos, toReplace.length(), newRepl);
           // cout << s << " Replaced to " << newString << "\n";
        }
    }
    return newString;
}

string convertToNumbers(string s) {
    string output = s;
    string numbers [] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for (int i = 0; i < 9; i++) {
        output = replace_all(output, numbers[i],to_string(i+1));
    }
    return output;
}

int findFigures(string input) {
    vector<int> integers;
    string s = convertToNumbers(input);
    for (char c : s) {
        int x = (int)c - 48;
        if (x < 10) {
            integers.push_back(x);
        }
    }
    int twodigitNumbers;
    string c1 = to_string(integers.front());
    string c2 = to_string(integers.back());
    string out = c1 + c2;

    cout << input << " to " << s << " erg: " <<  out << "\n";

    twodigitNumbers = stoi(out);
  //  cout <<out << " \n";
    return twodigitNumbers;
}

int main()
{
    cout << "Hello World!\n";
    string line;
    ifstream input1("Day1Input.txt");
    vector<string> file;
    while (getline(input1, line))
    {
        file.push_back(line);
    }
    int sum = 0;
    for (string s : file) {
         int figures = findFigures(s);
         sum = sum + figures;
    }
    cout << sum;
}
