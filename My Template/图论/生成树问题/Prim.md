# Prim算法模板
```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
const int maxn = 200005;

int n, m;
vector<int> dis;
vector<bool> vis;
vector<vector<pair<int, int>>> edges;

struct node {
    int p, dis;
    friend bool operator < (const node& a, const node& b) {
        return a.dis > b.dis;
    }
};

int prim() {
    priority_queue<node> q;
    dis.assign(n + 1, INF);
    vis.assign(n + 1, 0);
    
    dis[1] = 0;
    q.push({1, 0});
    
    int sum = 0;
    int cnt = 0;
    
    while (!q.empty()) {
        int p = q.top().p;
        int d = q.top().dis;
        q.pop();
        
        if (vis[p]) continue;
        vis[p] = 1;
        sum += d;
        cnt++;
        
        for (const auto& e : edges[p]) {
            int to = e.first;
            int w = e.second;
            if (!vis[to] && dis[to] > w) {
                dis[to] = w;
                q.push({to, dis[to]});
            }
        }
    }

    return sum;
}

void solve() {
    cin >> n >> m;
    edges.assign(n + 1, vector<pair<int, int>>());
    
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    
    int ans = prim();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
```