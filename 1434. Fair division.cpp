// 1434. Fair division.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath> 
#include<iomanip>

using namespace std;

int main()
 {
    long long n, w, p;
    cin >> n >> w >> p;

    priority_queue<long double , vector<long double>, greater<long double>> servant;

    for (int i = 0;i < n;i++)
    {
        long double temp;
        cin >> temp;
        servant.push(temp);
    }

    long long coin = 0;

    if (n == 1)
    {
        cout << 0;
        return 0;
    }

    while (servant.top() != w)
    {
        long double a = servant.top();
        servant.pop();
        long double b = servant.top();
        servant.pop();
        coin += (a + b) * p;
        servant.push(a + b);
    }
    cout << fixed << setprecision(0) << ceil(0.01*coin);





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
