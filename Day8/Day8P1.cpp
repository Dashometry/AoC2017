#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
using std::string;
using std::unordered_map;
using std::vector;

void process_instruction(vector<string> &contents, unordered_map<string, int> &registers)
{
    string r1 = contents[0];
    string r2 = contents[4];
    if (registers.find(r1) == registers.end())
        registers[r1] = 0;
    if (registers.find(r2) == registers.end())
        registers[r2] = 0;

    int change = stoi(contents[2]);
    if (contents[1] == "dec")
        change *= -1;

    string cond = contents[5];
    int condNum = stoi(contents[6]);
    bool do_change = (cond == ">" && registers[r2] > condNum) || (cond == "<" && registers[r2] < condNum) || (cond == ">=" && registers[r2] >= condNum) || (cond == "<=" && registers[r2] <= condNum) || (cond == "==" && registers[r2] == condNum) || (cond == "!=" && registers[r2] != condNum);
    if (do_change)
    {
        registers[r1] += change;
        // std::cout << r1 << ": " << registers[r1] << "\n";
    }
}

void splitLine(string &line, vector<string> &contents)
{
    char delimiter = ' ';
    int split = line.find_first_of(delimiter);
    while (split != string::npos)
    {
        contents.insert(contents.end(), line.substr(0, split));
        line = line.substr(split + 1);
        split = line.find_first_of(delimiter);
    }
}

int main()
{
    unordered_map<string, int> registers;

    std::ifstream f("inputDay8.txt");
    string line;
    int max_val = 0;

    while (getline(f, line))
    {
        vector<string> contents;
        line = line.append(" ");
        splitLine(line, contents);
        process_instruction(contents, registers);
    }

    for (auto &p : registers)
    {
        max_val = std::max(max_val, p.second);
    }

    std::cout << max_val;
    return 0;
}