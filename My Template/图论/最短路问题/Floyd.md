# Floyd算法求多源最短路模板（带路径记录）

```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

int n, m;
vector<vector<int>> dis, nxt;

void floyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (dis[i][k] == INF) continue;
            for (int j = 0; j < n; j++) {
                if (dis[k][j] == INF) continue;
                if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
}

vector<int> get_path(int u, int v) {
    if (dis[u][v] == INF) return {};
    vector<int> path = {u};
    while (u != v) {
        u = nxt[u][v];
        path.push_back(u);
    }
    return path;
}

void solve() {
    cin >> n >> m;
    
    dis.assign(n, vector<int>(n, INF));
    nxt.assign(n, vector<int>(n, -1));
    
    for (int i = 0; i < n; i++) {
        dis[i][i] = 0;
        nxt[i][i] = i;
    }
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        if (w < dis[u][v]) {
            dis[u][v] = w;
            dis[v][u] = w;
            nxt[u][v] = v;
            nxt[v][u] = u;
        }
    }
    
    floyd();
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