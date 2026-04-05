# 倍增法求LCA模板
```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
const int LOG = 20;  // 2^20 > 1e6

int n, m;
vector<vector<int>> g;
vector<vector<int>> up;
vector<int> depth;

void dfs(int u, int fa) {
    up[u][0] = fa;
    for (int i = 1; i < LOG; i++) {
        up[u][i] = up[up[u][i-1]][i-1];
    }
    for (int v : g[u]) {
        if (v == fa) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++) {
        if (diff >> i & 1) {
            u = up[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

void solve() {
    cin >> n >> m;
    g.resize(n + 1);
    up.assign(n + 1, vector<int>(LOG));
    depth.assign(n + 1, 0);
    
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(1, 1);
    
    while (m--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
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