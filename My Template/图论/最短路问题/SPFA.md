# 基础SPFA模板

```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

int n, m;
vector<int> dis;
vector<bool> vis;
vector<vector<pair<int, int>>> edges;

void spfa() {
    queue<int> q;
    dis.assign(n, INF);
    vis.assign(n, 0);
    dis[0] = 0;
    vis[0] = 1;
    q.push(0);
    
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        vis[p] = 0;
        
        for (auto& e : edges[p]) {
            int to = e.first;
            int w = e.second;
            if (dis[to] > dis[p] + w) {
                dis[to] = dis[p] + w;
                if (!vis[to]) {
                    vis[to] = 1;
                    q.push(to);
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    edges.resize(n);
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    
    spfa();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--)
    solve();
    return 0;
}
```