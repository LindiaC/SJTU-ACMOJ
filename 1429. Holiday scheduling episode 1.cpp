// 1429. Holiday scheduling episode 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
	int start;
	int end;
	int pay;
};

Job job[100001];


bool cmpend(Job a, Job b)
{
	return a.end<b.end;
}



int main()

{
	ios::sync_with_stdio(false);
	int n, m, x;
	cin >> n >> m >> x;



	for (int i = 1;i <= m;i++)
	{
		cin >> job[i].start >> job[i].end >> job[i].pay;
	}

	sort(job+1,job+m+1, cmpend);


	int dp[100001][2];

	dp[0][0] = 0;
	dp[0][1] = 0;
	int end = 0;

	for (int i = 1;i <= m;i++)
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

		int maxtemp = 0;

		for (int j = 1;j < i;j++)
		{
			if (job[j].end >= job[i].start)
			{
				break;
			}
			end = j;
		}
		dp[i][1] = dp[end + 1][0] + job[i].pay;
	}

	cout << max(dp[m][0], dp[m][1]);


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