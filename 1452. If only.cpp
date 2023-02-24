#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1e5 + 10;
vector<int> g[MAXN];
bool vis[MAXN];
int n, m, s, t, k;

bool bfs(int s, int t, int k) {
    queue<pair<int, int>> q;
    q.push({ s, 0 });
    vis[s] = true;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int u = cur.first, step = cur.second;
        if (u == t && step <= k) return true;
        if (step >= k) continue;
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push({ v, step + 1 });
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m >> s >> t >> k;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        g[i].push_back(i);
    }
    if (bfs(s, t, k)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
