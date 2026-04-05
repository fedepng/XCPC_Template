# Kruskal算法模板

```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

struct DSU {
    vector<int> fa;
    
    DSU(int n) {
        fa.resize(n + 1);
        for (int i = 1; i <= n; i++) fa[i] = i;
    }
    
    int find(int x) {
        if (x != fa[x]) fa[x] = find(fa[x]);
        return fa[x];
    }
    
    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return 0;
        fa[fx] = fy;
        return 1;
    }
};

struct edge {
    int u, v, w;
};

int n, m;
vector<edge> edges;

int kruskal() {
    sort(edges.begin(), edges.end(), [](edge& a, edge& b) {
        return a.w < b.w;
    });
    
    DSU dsu(n);
    int ans = 0, cnt = 0;
    
    for (auto& e : edges) {
        if (dsu.merge(e.u, e.v)) {
            ans += e.w;
            cnt++;
            if (cnt == n - 1) break;
        }
    }
    
    return ans;
}

void solve() {
    cin >> n >> m;
    edges.clear();
    
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    
    int ans = kruskal();
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