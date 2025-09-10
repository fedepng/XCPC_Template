# Tarjon算法模板

```cpp
#include<bits/stdc++.h>
#define int long long
#define maxn 200005

const int INF = 1e18;

using namespace std;

vector<int> edges[maxn];
vector<int> st;
int dfn[maxn], low[maxn], bel[maxn], top, n, m, cnt, idx;
bool ins[maxn];

void dfs(int u) {
    dfn[u] = low[u] = ++cnt;
    st.push_back(u);
    ins[u] = 1;
    for (int i : edges[u]) {
        if (!dfn[i]) {
            dfs(i);
            low[u] = min(low[u], low[i]);
        } else if (ins[i]) {
            low[u] = min(low[u], dfn[i]);
        }
    }
    if (low[u] == dfn[u]) {
        int v;
        ++idx;
        do {
            v = st.back();
            st.pop_back();
            bel[v] = idx;
            ins[v] = 0;
        } while (v != u);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) if (!dfn[i]) dfs(i);
}
```