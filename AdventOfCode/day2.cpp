#include "day2.h";

string differentColors[] = { "red","blue","green" };

std::vector<string> day2::splitInput(string input, string delimiter) {
    string newInput = input;
    int pos = 0;
    string token;
    std::vector<string> run;
    while (pos >= 0) {
        pos = newInput.find(delimiter);
        token = newInput.substr(0, pos);
        run.push_back(token);
        newInput.erase(0, pos + delimiter.length() + 1);
    }

    return run;
}


int day2::findCubeCount(string input, string color) {
    string newInput = input;
    string value = "0";
    int pos = newInput.find(color);
    if (pos >= 0) {
        value = newInput.substr(0, pos);
    }

    return stoi(value);
}

int day2::splitGamePhase(string game, string delimiter) {
    int maxCubes[] = { 12,14,13 };

    std::vector<string> run = splitInput(game, delimiter);
    string firstString = run[0];
    string newDelimiter = ":";
    int pos = firstString.find(newDelimiter);
    firstString.erase(0, pos + newDelimiter.length() + 1);
    run[0] = firstString;
    int minCubes [] = {0,0,0};
    for (string runs : run) {
        std::vector<string> cubes = splitInput(runs, ",");
        int foundCubes [] = {0,0,0};
        for (int i = 0; i < differentColors->size();  i++) {
            for (string cube : cubes) {
                int found = findCubeCount(cube,differentColors[i]);
                foundCubes[i] = foundCubes[i] + found;
                //cout << found << " " << differentColors[i] << "\n";
                
            }
        }
        for (int i = 0; i < 3; i++) {
            if (foundCubes[i] > minCubes[i]) {
                minCubes[i] = foundCubes[i];
            }
        }
//        if (foundCubes[0] > maxCubes[0] || foundCubes[1] > maxCubes[1] || foundCubes[2] > maxCubes[2]) {
//            return false;
//        }
       // cout << "---" << foundCubes[0] << "\n";

    }

   // cout << run[0] << "|" << run[1] << "\n";

    return minCubes[0]* minCubes[1] * minCubes[2];
}

int day2::day2Execute()
{
    //RED|BLUE|GREEN
    int games = 0;

    std::vector<string> data = usefullStuff::readInputEachLine("Day2Input.txt");
    for (int l = 0; l < data.size(); l++) {
        int gamePower= splitGamePhase(data[l], ";");
       // cout << "game " << l+1<<  ": " << game[0] << "|" << game[1] << "|" << game[2] << "\n";
        games = games + gamePower;
    }
    cout << games;
    

    return 0;
}
