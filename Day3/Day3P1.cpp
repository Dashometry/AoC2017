#include <iostream>
int input = 277678;
int curr = 1;
using namespace std;

void modify_pos(int &x, int &y, int change_x, int change_y, int count)
{
    for (int i = 0; i < count; i++)
    {
        x += change_x;
        y += change_y;
        curr++;
        if (curr == input)
        {
            cout << abs(x) + abs(y);
            exit(0);
        }
    }
}

int main()
{
    int change_amount = 1;
    int x = 0;
    int y = 0;

    while (true)
    {
        modify_pos(x, y, 1, 0, change_amount);
        modify_pos(x, y, 0, 1, change_amount);
        change_amount += 1;
        modify_pos(x, y, -1, 0, change_amount);
        modify_pos(x, y, 0, -1, change_amount);
        change_amount += 1;
    }

    return 0;
}