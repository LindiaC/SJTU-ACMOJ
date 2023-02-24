// 1539. 前序序列合法性.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool isPreorderValid(string tree)
{
    if (tree[0] == '#') return false;
    if (tree.size() == 0) return true;

    int deg = 1;
    for (int i = 0;i < tree.size();i++)
    {
        if (tree[i] != ',' and tree[i] != '#')
        {
            deg++;
            while (i<tree.size() and tree[i] != ',') i++;
            continue;
        }
        if (tree[i] == '#')
        {
            deg--;
            while (i < tree.size() and tree[i] != ',') i++;
            continue;
        }
    }
    return deg == 0;
}

int main()
{
    string s;
    cin >> s;
    cout << isPreorderValid(s);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
