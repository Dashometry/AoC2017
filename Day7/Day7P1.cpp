#include <iostream>
#include <fstream>
#include <vector>
using std::string;
using std::vector;

struct Node
{
    Node *parent;
    vector<Node *> children;
    string name;
    int weight;
    Node(string name)
    {
        this->parent = NULL;
        this->name = name;
    }
    Node(string name, int weight)
    {
        this->parent = NULL;
        this->name = name;
        this->weight = weight;
    }
};

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

void getNodeWithName(string &name, vector<Node *> &nodes, Node *&nodeP)
{
    for (Node *n : nodes)
    {
        if ((*n).name == name)
            nodeP = n;
    }
}

void createNodes(vector<Node *> &nodes, vector<string> &contents)
{
    string name = contents[0];
    int weight = std::stoi(contents[1].substr(1, contents[1].length() - 2));
    Node *parent = NULL;
    getNodeWithName(name, nodes, parent);
    if (parent == NULL)
        parent = new Node(name, weight);
    else
        (*parent).weight = weight;

    for (int i = 3; i < contents.size(); i++)
    {
        name = i != contents.size() - 1 ? contents[i].substr(0, contents[i].length() - 1) : contents[i];
        Node *child = NULL;
        getNodeWithName(name, nodes, child);
        if (child == NULL)
            child = new Node(name);
        else
            (*parent).weight = weight;
        (*child).parent = parent;
        (*parent).children.insert((*parent).children.end(), child);
        nodes.insert(nodes.end(), child);
    }
    nodes.insert(nodes.end(), parent);
}

int main()
{
    vector<Node *> nodes;
    std::ifstream f("inputDay7.txt");
    std::string line;
    while (getline(f, line))
    {
        vector<string> contents;
        line = line.append(" ");
        splitLine(line, contents);
        createNodes(nodes, contents);
    }

    for (Node *n : nodes)
    {
        if ((*n).parent == NULL)
            std::cout << (*n).name;
    }

    return 0;
}
