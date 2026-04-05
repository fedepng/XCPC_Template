# EK解决网络流问题模板
```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

int n, m, s, t;
vector<int> pre_v, pre_e, min_flow;
vector<bool> vis;
vector<vector<tuple<int, int, int>>> edges;  // to, cap, rev

void add_edge(int u, int v, int w) {
    edges[u].push_back({v, w, (int)edges[v].size()});
    edges[v].push_back({u, 0, (int)edges[u].size() - 1});
}

bool bfs() {
    pre_v.assign(n + 1, -1);
    pre_e.assign(n + 1, -1);
    min_flow.assign(n + 1, INF);
    vis.assign(n + 1, false);
    
    queue<int> q;
    q.push(s);
    vis[s] = true;
    pre_v[s] = s;
    min_flow[s] = INF;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int i = 0; i < (int)edges[u].size(); i++) {
            auto [to, cap, rev] = edges[u][i];
            if (!vis[to] && cap > 0) {
                vis[to] = true;
                pre_v[to] = u;
                pre_e[to] = i;
                min_flow[to] = min(min_flow[u], cap);
                q.push(to);
                if (to == t) return true;
            }
        }
    }
    return false;
}

int max_flow() {
    int res = 0;
    while (bfs()) {
        int f = min_flow[t];
        res += f;
        int v = t;
        while (v != s) {
            int u = pre_v[v];
            int e = pre_e[v];
            auto& [to, cap, rev] = edges[u][e];
            cap -= f;
            auto& [rev_to, rev_cap, rev_rev] = edges[v][rev];
            rev_cap += f;
            v = u;
        }
    }
    return res;
}

void solve() {
    cin >> n >> m >> s >> t;
    edges.resize(n + 1);
    
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    
    cout << max_flow() << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
```