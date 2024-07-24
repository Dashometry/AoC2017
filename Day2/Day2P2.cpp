#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int find_divided_val(vector<int> row)
{
    for (int i = 0; i < row.size(); i++)
    {
        for (int j = i + 1; j < row.size(); j++)
        {
            if (row[i] % row[j] == 0)
            {
                return row[i] / row[j];
            }
            if (row[j] % row[i] == 0)
            {
                return row[j] / row[i];
            }
        }
    }
    return -1;
}

int main()
{
    vector<vector<int>> grid;
    string line;
    int sum = 0;
    ifstream f("inputDay2.txt");
    char delimiter = '\t';
    if (f.is_open())
    {
        while (getline(f, line))
        {
            vector<int> row;
            int split_index = line.find_first_of(delimiter);
            ;

            while (split_index != string::npos)
            {
                int num = stoi(line.substr(0, split_index));
                row.insert(row.end(), num);
                line = line.substr(split_index + 1);

                split_index = line.find_first_of(delimiter);
            }
            int num = stoi(line);
            row.insert(row.end(), num);

            grid.insert(grid.end(), row);
        }

        f.close();
    }

    for (vector<int> row : grid)
    {
        sum += find_divided_val(row);
    }

    cout << sum;

    return 0;
}
