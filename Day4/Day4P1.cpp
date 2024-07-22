#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int valid_count = 0;

void check_valid(string line, char delimiter)
{
    vector<string> words;
    int split = line.find_first_of(delimiter);

    while (split != string::npos)
    {
        string word = line.substr(0, split);
        if (find(words.begin(), words.end(), word) == words.end())
            words.insert(words.end(), word);
        else
            return;
        line = line.substr(split + 1);
        split = line.find_first_of(delimiter);
    }
    valid_count++;
}

int main()
{
    string line;
    ifstream f("inputDay4.txt");
    char delimiter = ' ';

    if (f.is_open())
    {
        while (getline(f, line))
        {
            check_valid(line + " ", delimiter);
        }
        f.close();
    }

    cout << valid_count;

    return 0;
}