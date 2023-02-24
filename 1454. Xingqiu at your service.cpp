// 1454. Xingqiu at your service.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int main()
{
    long long n;
    double p;
    cin >> n >> p;
    double dp[200000 + 1] = {0};
    dp[1] = 1;
    dp[2] = p * 1 + (1 - p) * 2;

    for (int i = 3 ;i <= 2 * n;i++)
    {
        dp[i] = p * (dp[i - 2] + 1) + (1 - p) * (dp[i - 1] + 1);
    }
    cout << fixed;
    cout << dp[2*n];


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
