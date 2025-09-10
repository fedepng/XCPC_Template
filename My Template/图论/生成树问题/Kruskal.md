# Kruskal算法模板

```cpp
#include<bits/stdc++.h>
#define int long long
#define maxn 200005

const int INF = 1e18;

using namespace std;

struct edge {
    int u, v, w;
};

vector<edge> edges;
int fa[maxn], n, m, ans, cnt;

int find(int x) {
    if (x != fa[x]) return fa[x] = find(fa[x]);
    return x;
}

void kruskal() {
    sort(edges.begin(), edges.end(), [](edge a, edge b) {
        return a.w < b.w;
    });
    for (auto e : edges) {
        int u = find(e.u);
        int v = find(e.v);
        if (u == v) continue;
        ans += e.w;
        fa[u] = v;
        cnt++;
    }
}
```