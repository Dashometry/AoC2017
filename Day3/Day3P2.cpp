#include <iostream>
#include <unordered_map>
using namespace std;
int input = 277678;
unordered_map<string, int> nums;

int get_num(int x, int y)
{
    string key = to_string(x) + " " + to_string(y);
    if (nums.find(key) != nums.end())
        return nums[key];
    return 0;
}

void add_nums(int &x, int &y, int change_x, int change_y, int count)
{
    for (int i = 0; i < count; i++)
    {
        x += change_x;
        y += change_y;
        int sum = 0;

        sum += get_num(x + 1, y);
        sum += get_num(x - 1, y);
        sum += get_num(x, y + 1);
        sum += get_num(x, y - 1);
        sum += get_num(x + 1, y + 1);
        sum += get_num(x + 1, y - 1);
        sum += get_num(x - 1, y + 1);
        sum += get_num(x - 1, y - 1);

        if (sum > input)
        {
            cout << sum;
            exit(0);
        }
        string key = to_string(x) + " " + to_string(y);
        nums[key] = sum;
    }
}

int main()
{
    int change_amount = 1;
    int x = 0;
    int y = 0;
    nums["0 0"] = 1;

    while (true)
    {
        add_nums(x, y, 1, 0, change_amount);
        add_nums(x, y, 0, 1, change_amount);
        change_amount += 1;
        add_nums(x, y, -1, 0, change_amount);
        add_nums(x, y, 0, -1, change_amount);
        change_amount += 1;
    }

    return 0;
}