# 基础Dijkstra模板

```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

int n, m;
vector<int> dis;
vector<vector<pair<int, int>>> edges;

struct node {
    int p, dis;
    friend bool operator < (const node& a, const node& b) {
        return a.dis > b.dis;
    }
};

void dij() {
    priority_queue<node> q;
    dis.assign(n, INF);
    dis[0] = 0;
    q.push({0, 0});
    
    while (!q.empty()) {
        int p = q.top().p;
        int d = q.top().dis;
        q.pop();
        
        if (d > dis[p]) continue;
        
        for (const auto& e : edges[p]) {
            int to = e.first;
            int w = e.second;
            if (dis[to] > dis[p] + w) {
                dis[to] = dis[p] + w;
                q.push({to, dis[to]});
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
    
    dij();
    
    for (int i = 0; i < n; i++) {
        cout << dis[i] << " \n"[i == n - 1];
    }
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