# 分层图Dijkstra模板

```cpp
#include<bits/stdc++.h>
#define int long long

const int INF = 1e18;

using namespace std;

int n, m, k;
vector<int> dis;
vector<vector<pair<int, int>>> edges;

struct node{
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
        int p = q.top().p, d = q.top().dis;
        q.pop();
        if (d > dis[p]) continue;
        for (auto& e : edges[p]) {
            if (dis[e.first] > dis[p] + e.second) {
                dis[e.first] = dis[p] + e.second;
                q.push({e.first, dis[e.first]});
            }
        }
    }
} 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    dis.resize(n * (k + 1));
    edges.resize(n * (k + 1));

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        for (int j = 0; j <= k; j++) {
            edges[a + j * n].push_back({b + j * n, c});
            if (j != k) edges[a + j * n].push_back({b + (j + 1) * n, 0});
        }
    }

    dij();
}
```