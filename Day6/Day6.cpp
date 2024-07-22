#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using std:: string;
using std:: vector;
using std:: unordered_set;
using std:: cout;

const string input = "0	5	10	0	11	14	13	4	11	8	8	7	1	4	12	11";

void get_memory(vector<int> &memory, string input, char delimiter){
    int split = input.find_first_of(delimiter);
    while (split != string:: npos){
        int num = stoi(input.substr(0, split));
        memory.insert(memory.end(), num);
        input = input.substr(split + 1);
        split = input.find_first_of(delimiter);
    }
    int num = stoi(input);
    memory.insert(memory.end(), num); 
}

int get_max_index(vector<int> &array){
    int max_i = 0;
    for (int i = 1; i < array.size(); i++){
        if (array[i] > array[max_i])
            max_i = i;
    }
    return max_i;
}

string get_state(vector<int> &array){
    string state = "";
        for (int i : array){
            state = state + std:: to_string(i) + ' ';
        }
        return state;
}

int main(){
    vector<int> memory;
    get_memory(memory, input, '\t');
    // for part 2 (using input as the last line in part 1):
    //get_memory(memory, "10 9 8 7 6 5 4 3 1 1 0 15 14 13 11 12", ' ');
    unordered_set<string> visited;
    int cycles = 0;

    visited.insert(get_state(memory));

    while (true){
        cycles++;
        int max_index = get_max_index(memory);
        int value = memory[max_index];
        memory[max_index] = 0;

        int index = (max_index + 1) % memory.size();
        for (int i = 0; i < value; i++){
            memory[index]++;
            index = (index + 1) % memory.size();
        }

        string state = get_state(memory);

        if (visited.count(state) == 1){
            cout << cycles;
            return 0;
        }
        visited.insert(state);
        
    }
    return 0;
}