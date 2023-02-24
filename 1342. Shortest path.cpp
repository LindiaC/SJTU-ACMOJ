// 1342. Shortest path.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

using namespace std;

int n, m, s, t;
#define maxsize 2500;
long long G[2501][2501] = {0};

bool marked[2501] = {0};

void readgraph()
{
    cin >> n; //vertices, 1-based
    cin >> m; //edges
    cin >> s; //start
    cin >> t; //end
    
    int t1, t2, l;
    for (int i = 0;i < m;i++)
    {
        cin >> t1 >> t2 >> l;
        if (G[t1][t2] > 0 and G[t1][t2] <= l) continue;
        G[t1][t2] = l;
        G[t2][t1] = l;
        
    }
}

void explore(int v)
{
    marked[v] = true;
    for (int i = 1;i <= n;i++)
    {
        if (G[v][i] > 0)
        {
            if (marked[i] == false) explore(i);
        }
    }
}


int smallestv(bool T[], long long tdist[])
{
    long long min_length = -1;
    int min_index = -1;

    for (int i = 1;i <= n;i++)
    {
        if (T[i] == true) continue;
        if ((tdist[i] >=0 and tdist[i] <= min_length) or min_length<0 or min_index<0)
        {
            min_index = i;
            min_length = tdist[min_index];
        }
    }
    return min_index;
}

int main()
{
    readgraph();

    //Initialize
    bool T[2500] = { 0 };
    T[s] = true;
    long long tdist[2500];
    for (int i = 1;i <= n;i++)
    {
        tdist[i] = -1;
    }
    tdist[s] = 0;
    for (int i = 1;i <= n;i++)
    {
        if (G[s][i]>0) tdist[i] = G[s][i];
    }



    int pre[2500] = { 0 };
    while(1)
    {
        //find v not in T with smallest tdist[v]
        int v = smallestv(T, tdist);
        T[v] = true;
        if (pre[v] == 0) pre[v] = s;
        if (v == t) break;

        //Update tdist[u] for all other u
        for (int u = 1;u <= n;u++)
        {
            if (G[v][u] > 0 and T[u] == false)
            {
                if (tdist[u] >= tdist[v] + G[v][u] or tdist[u]<0)
                {
                    pre[u] = v;
                    tdist[u] = tdist[v] + G[v][u];
                }
            }
        }
    }

    long long path = 0;
    int u = t;

    while (1)
    {
        path += G[u][pre[u]];
        if (pre[u] == s) break;
        u = pre[u];
    }

    cout << path;


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
