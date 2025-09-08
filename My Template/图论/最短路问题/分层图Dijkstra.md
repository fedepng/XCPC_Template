# 分层图Dijkstra模板

```cpp
#include<bits/stdc++.h>
#define int long long
#define maxn 200005
#define maxk 25

const int INF = 1e18;

using namespace std;

int n, m, k, dis[maxn * maxk];
bool vis[maxn * maxk];
vector<pair<int, int>> edges[maxn * maxk];

struct node{
    int p, dis;
    friend bool operator < (const node& a, const node& b) {
        return a.dis > b.dis;
    }
};

void dij() {
    priority_queue<node> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    q.push({1, 0});
    while (!q.empty()) {
        int p = q.top().p;
        q.pop();
        if (vis[p]) continue;
        vis[p] = 1;
        for (const auto& e : edges[p]) {
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
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int i = 0; i <= k; i++) {
            edges[a + i * n].push_back({b + i * n, c});
            if (i != k) edges[a + i * n].push_back({b + (i + 1) * n, 0});
        }
    }
    dij();
}

```