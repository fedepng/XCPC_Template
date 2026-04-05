# 分层图Dijkstra模板
```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

int n, m, k;
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
    dis.assign(n * (k + 1), INF);
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
    cin >> n >> m >> k;
    edges.resize(n * (k + 1));
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        
        for (int j = 0; j <= k; j++) {
            edges[u + j * n].push_back({v + j * n, w});
            if (j < k) {
                edges[u + j * n].push_back({v + (j + 1) * n, 0});
            }
        }
    }
    
    dij();
    
    int ans = INF;
    for (int i = 0; i <= k; i++) {
        ans = min(ans, dis[n - 1 + i * n]);
    }
    cout << ans << '\n';
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