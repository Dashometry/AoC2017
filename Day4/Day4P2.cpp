#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int valid_count = 0;

string get_sorted(string word)
{
    vector<char> chars(word.begin(), word.end());

    // Bubble sort ew
    for (int i = 0; i < chars.size(); i++)
    {
        for (int j = 0; j < chars.size() - i - 1; j++)
        {
            if (chars[j] > chars[j + 1])
            {
                char temp = chars[j];
                chars[j] = chars[j + 1];
                chars[j + 1] = temp;
            }
        }
    }

    string result(chars.begin(), chars.end());
    // cout << "before: " << word << ", after: " << result << "\n";
    return result;
}

bool check_valid(string line, char delimiter)
{
    vector<string> words;
    int split = line.find_first_of(delimiter);

    while (split != string::npos)
    {
        string word = line.substr(0, split);
        word = get_sorted(word);
        if (find(words.begin(), words.end(), word) == words.end())
            words.insert(words.end(), word);
        else
            return false;
        line = line.substr(split + 1);
        split = line.find_first_of(delimiter);
    }
    valid_count++;
    return true;
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