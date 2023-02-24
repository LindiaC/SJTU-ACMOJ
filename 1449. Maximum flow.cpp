// 1449. Maximum flow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int source = 1;
int sink = 0;
#define M 201
#define N 201
#define INF 1000000000

int n = 0; //actual sink
int m = 0;



struct edge 
{
    int next, to, flow;
};
edge e[M * 2]; // remember there are back edges
int edge_cnt = 2; // to make reverse(e[x]) = e[x ^ 1], and avoid use number 0. M should be slightly larger than actual.
int list_head[N]; // init as 0
void add_edge(int u, int v, int flow) {
    e[edge_cnt] = { list_head[u], v, flow };
    list_head[u] = edge_cnt++;
    e[edge_cnt] = { list_head[v], u, 0 };
    list_head[v] = edge_cnt++;
}
void traverse(int u) {
    for (int cur = list_head[u]; cur != 0; cur = e[cur].next) {
        // do something with e[cur]
    }
}

int level[N];


bool make_level() {
    memset(level, -1, sizeof(level));
    level[source] = 0;
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = list_head[x]; i != 0; i = e[i].next) {
            if (e[i].flow > 0 && level[e[i].to] < 0) {
                level[e[i].to] = level[x] + 1;
                q.push(e[i].to);
            }
        }
    }
    return level[sink] >= 0;
}


int cur[N];
int dfs(int x, int flow) {
    if (x == sink) return flow;
    int used = 0;
    for (int& i = cur[x]; i != 0; i = e[i].next) { // i : reference to cur[x]
        if (e[i].flow > 0 && level[x] + 1 == level[e[i].to]) {
            int ret = dfs(e[i].to, min(e[i].flow, flow - used));
            used += ret;
            e[i].flow -= ret;
            e[i ^ 1].flow += ret;
            if (used == flow) break;
        }
    }
    return used;
}
int dinic() {
    int ans = 0;
    while (make_level()) {
        for (int i = 1; i <= n; i++) { // initialize cur[]
            cur[i] = list_head[i];
        }
        ans += dfs(source, INF);
    }
    return ans;
}



int main()
{
    cin >> sink;
    n = sink;
    cin >> m;
    for (int i = 0;i < m;i++)
    {
        int u, v, flow;
        cin >> u >> v >> flow;
        add_edge(u, v, flow);

    }
    int maxflow=dinic();
    cout << maxflow;
    return 0;



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
