#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string line;
    ifstream f("inputDay5.txt");

    vector<int> jumps;

    if (f.is_open()){
        while(getline(f, line)){
            jumps.insert(jumps.end(), stoi(line));
        }
        f.close();
    }

    int i = 0;
    int steps = 0;

    while (i >= 0 && i < jumps.size()){
        int jump = jumps[i];
        jumps[i]++;
        i += jump;
        steps++;
    }

    cout << steps;

    return 0;
}