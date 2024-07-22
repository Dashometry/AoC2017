#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string line;
    int sum = 0;
    ifstream f("inputDay2.txt");
    char delimiter = '\t';
    if (f.is_open())
    {
        while (getline(f, line))
        {
            int split_index = line.find_first_of(delimiter);
            ;
            int max = 0;
            int min = 99999;

            while (split_index != string::npos)
            {
                int num = stoi(line.substr(0, split_index));
                if (num > max)
                    max = num;
                if (num < min)
                    min = num;

                line = line.substr(split_index + 1);
                split_index = line.find_first_of(delimiter);
            }
            int num = stoi(line);
            if (num > max)
                max = num;
            if (num < min)
                min = num;
            sum += (max - min);
        }
        f.close();
    }
    cout << sum;

    return 0;
}