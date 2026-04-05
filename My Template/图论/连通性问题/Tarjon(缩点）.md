# Tarjon算法模板（缩点）

```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

int n, m;
vector<vector<int>> edges, dag;
vector<int> dfn, low, bel, sz, st;
vector<bool> ins;
int cnt, idx;

void dfs(int u) {
    dfn[u] = low[u] = ++cnt;
    st.push_back(u);
    ins[u] = true;
    
    for (int v : edges[u]) {
        if (!dfn[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    
    if (low[u] == dfn[u]) {
        idx++;
        int v;
        do {
            v = st.back();
            st.pop_back();
            bel[v] = idx;
            sz[idx]++;
            ins[v] = false;
        } while (v != u);
    }
}

void tarjan() {
    dfn.assign(n + 1, 0);
    low.assign(n + 1, 0);
    bel.assign(n + 1, 0);
    sz.assign(n + 1, 0);
    ins.assign(n + 1, false);
    st.clear();
    cnt = idx = 0;
    
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) dfs(i);
    }
}

void build_dag() {
    dag.assign(idx + 1, vector<int>());
    
    for (int u = 1; u <= n; u++) {
        for (int v : edges[u]) {
            if (bel[u] != bel[v]) {
                dag[bel[u]].push_back(bel[v]);
            }
        }
    }
    
    // 去重
    for (int i = 1; i <= idx; i++) {
        sort(dag[i].begin(), dag[i].end());
        dag[i].erase(unique(dag[i].begin(), dag[i].end()), dag[i].end());
    }
}

void solve() {
    cin >> n >> m;
    edges.assign(n + 1, vector<int>());
    
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }
    
    tarjan();
    build_dag();
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