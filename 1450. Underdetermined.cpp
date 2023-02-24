#include <iostream>
#include <queue>
#include <cstring>
#define inf 0x3f3f3f3f
using namespace std;
const int N = 205, M = 20005;

int n, S, T;
int h[N], e[M], ne[M], f[M], idx;
int cur[N], d[N];

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx++;
    e[idx] = a, ne[idx] = h[b], f[idx] = 0, h[b] = idx++;
}

bool bfs()
{
    queue<int>q;
    memset(d, -1, sizeof d);
    d[S] = 0, q.push(S);
    while (q.size())
    {
        int t = q.front();q.pop();
        for (int i = h[t];~i;i = ne[i])
        {
            int ver = e[i];
            if (d[ver] == -1 && f[i])
            {
                d[ver] = d[t] + 1;
                q.push(ver);
            }
        }
    }
    return d[T] != -1;
}

int dinic(int u, int limit)
{
    if (u == T)return limit;
    int flow = 0;
    for (int i = cur[u];~i;i = ne[i])
    {
        cur[u] = i;
        int ver = e[i];
        if (d[ver] == d[u] + 1 && f[i])
        {
            int t = dinic(ver, min(f[i], limit - flow));
            if (!t)d[ver] = -1;
            flow += t, f[i] -= t, f[i ^ 1] += t;
            if (flow == limit)break;
        }
    }
    return flow;
}

int maxflow()
{
    int res = 0, flow;
    while (bfs())
    {
        memcpy(cur, h, sizeof h);
        while (flow = dinic(S, inf))res += flow;
    }
    return res;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n;
    S = 0, T = n * n + 1;
    int cnt = 0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
        {
            int val;
            cin >> val;
            if (val == 1)
            {
                add(S, i*n + j, 1);
                cnt++;
            }
            else add(i*n + j, T, 1);
            if (i > 1) add(i*n + j, (i - 1)*n + j, inf);
            if (i < n) add(i*n + j, (i + 1)*n + j, inf);
            if (j > 1) add(i*n + j, i*n + j - 1, inf);
            if (j < n) add(i*n + j, i*n + j + 1, inf);
        }
    }
    int flow = maxflow();
    if (flow == cnt)
    {
        cout << "It is possible to make the determinant non-zero by modifying some 1's to 0's" << endl;
        cout << "Modified matrix: " << endl;
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= n;j++)
            {
                int t = i * n + j;
                if (d[t] != -1)cout << 0 << " ";
                else cout << 1 << " ";
            }
            cout << endl;
        }
    }
    else cout << "It is not possible to make the determinant non-zero by modifying any 1's to 0's" << endl;
    return 0;
}


