// 1341. 2-SAT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>



using namespace std;

long long n, m;




void readgraph(vector<vector<int>>& G, vector<vector<int>>& G_R, int n, int m)
{
    int x_a,x_b;
    bool value_a, value_b;

    //the vertex 2i-1 means x_i=0, 2i means x_i=1
    for (int i = 1;i <= m;i++)
    {
        cin >> x_a >> value_a >> x_b >> value_b; //the original condition is x_a=value_a or x_b=value_b


        G[2 * x_a - 1 + !value_a].push_back(2 * x_b - 1 + value_b);
        G_R[2 * x_b - 1 + value_b].push_back(2 * x_a - 1 + !value_a);


        G[2 * x_b - 1 + !value_b].push_back(2 * x_a - 1 + value_a);
        G_R[2 * x_a - 1 + value_a].push_back(2 * x_b - 1 + !value_b);

    }
}

void explore_time(int v, vector<vector<int>> &G, vector<int>& marked, vector<int>& finish, int &seq)
{


    marked[v] = true;
    for (int i=0;i<G[v].size();i++)
    {
        if (marked[G[v][i]] == false) explore_time(G[v][i],G, marked, finish,seq);
    }
    finish[seq] = v;
    seq++;
}


void dfs_time_G(vector<vector<int>> &G, vector<int>& marked,vector<int>& finish)
{
    int time = 0;
    int seq = 1;
    for (int v = 1;v <= 2 * n;v++)
    {
        if (marked[v]) continue;
        if (!G[v].size())
        {
            marked[v] = true;
            finish[seq] = v;
            seq++;
        }
        else explore_time(v, G, marked, finish, seq);
    }
}

void explore_SCC(int v, vector<vector<int>> &G, vector<int>& marked, vector<int>& SCC, int SCC_counter)
{
    marked[v] = 2;
    SCC[v] = SCC_counter;
    for (int i = 0;i < G[v].size();i++)
    {
        int u = G[v][i];
        if (marked[u] ==1) explore_SCC(u, G, marked, SCC,SCC_counter);
    }

}



void dfs_SCC(vector<vector<int>> &G, vector<int>& marked, vector<int>& finish, vector<int>& SCC)
{
    long long SCC_counter = 1;
    for (int finish_time = 2 * n; finish_time >= 1;finish_time--)
    {
        long long v = finish[finish_time];
        if (marked[v] == 2) continue;
        if (!G[v].size())
        {
            marked[v] = 2;
            SCC[v] = SCC_counter;
            SCC_counter++;
            continue;
        }
        else
        {
            explore_SCC(v, G, marked, SCC, SCC_counter);
            SCC_counter++;
        }
    }
}


int main()
{
    cin >> n; // n variables need 2n vertices
    cin >> m; // m conditions need 2m edges

    std::ios::sync_with_stdio(false);

    vector<vector<int>> G(2 * n + 1);
    vector<vector<int>> G_R(2 * n + 1);

    readgraph(G,G_R,n,m);




    //DFS G_R and maintain a sorted list 
    vector<int> marked(2*n + 1, 0);
    vector<int> finish_G_R(2 * n + 1, 0);


    dfs_time_G(G_R, marked, finish_G_R);



    //vector<vector<int>>().swap(G_R);

    //DFS G by the ascending order of the finish time
    vector<int> SCC(2 * n + 1, 0);

    dfs_SCC(G, marked, finish_G_R, SCC);

    //vector<vector<int>>().swap(G);

    vector<int> result(n + 1);

    //generate the output
    for (int x = 1;x <= n;x++)
    {
        if (SCC[2 * x - 1] == SCC[2 * x])
        {
            cout << "No";
            return 0;
        }
        result[x] = SCC[2 * x - 1] < SCC[2 * x] ? 0 : 1;
    }
    
    cout << "Yes" << endl;
    for (int x = 1;x <= n;x++)
    {
        cout << result[x] << ' ';
    }

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
