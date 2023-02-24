// 1428. Minimum Spanning Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct Edge
{
    int a, b, w;

    bool operator < (const Edge& E) const
    {
        return w < E.w;
    }
};

Edge edge[200001];
int p[5001], m, n;

int find(int x)
{
    if (p[x] != x)
    {
        p[x] = find(p[x]);
    }
    return p[x];
}

int Kruskal()
{
    sort(edge, edge + m);
    for (int i = 1;i <= n;i++)
    {
        p[i] = i;
    }

    int len = 0, ver = 0;

    for (int i = 0;i < m;i++)
    {
        int a = edge[i].a;
        int b = edge[i].b;
        int w = edge[i].w;


        a = find(a);
        b = find(b);
        if (a != b)
        {
            p[a] = b;
            len += w;
            ver++;
        }
    }

    return len;
}




int main()
{
    cin >> n >> m;
    for (int i = 0;i < m;i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edge[i] = { a,b,w };
    }
    cout << Kruskal() << endl;
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
