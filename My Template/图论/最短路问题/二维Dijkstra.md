# 二维Dijkstra模板
```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

int n, m;
vector<int> dis1, dis2;
vector<vector<tuple<int, int, int>>> edges;

struct node {
    int p, d1, d2;
    friend bool operator < (const node& a, const node& b) {
        if (a.d1 != b.d1) return a.d1 > b.d1;
        return a.d2 > b.d2;
    }
};

void dij() {
    priority_queue<node> q;
    dis1.assign(n, INF);
    dis2.assign(n, INF);
    dis1[0] = 0;
    dis2[0] = 0;
    q.push({0, 0, 0});
    
    while (!q.empty()) {
        int p = q.top().p;
        int d1 = q.top().d1;
        int d2 = q.top().d2;
        q.pop();
        
        if (d1 > dis1[p] || (d1 == dis1[p] && d2 > dis2[p])) continue;
        
        for (const auto& [v, w1, w2] : edges[p]) {
            int nd1 = d1 + w1;
            int nd2 = d2 + w2;
            
            if (nd1 < dis1[v]) {
                dis1[v] = nd1;
                dis2[v] = nd2;
                q.push({v, nd1, nd2});
            } else if (nd1 == dis1[v] && nd2 < dis2[v]) {
                dis2[v] = nd2;
                q.push({v, nd1, nd2});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    edges.resize(n);
    
    for (int i = 0; i < m; i++) {
        int u, v, w1, w2;
        cin >> u >> v >> w1 >> w2;
        u--; v--;
        edges[u].push_back({v, w1, w2});
    }
    
    dij();
    
    for (int i = 0; i < n; i++) {
        cout << dis1[i] << ' ' << dis2[i] << '\n';
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