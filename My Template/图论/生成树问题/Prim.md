# Prim算法模板

```cpp

#include<bits/stdc++.h>
#define int long long
#define maxn 200005

const int INF = 1e18;

using namespace std;

int n, m, dis[maxn];
bool vis[maxn];
vector<pair<int, int>> edges[maxn];

struct node{
    int p, dis;
    friend bool operator < (const node& a, const node& b) {
        return a.dis > b.dis;
    }
};

void prim() {
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
            if (dis[e.first] > e.second) {
                dis[e.first] = e.second;
                q.push({e.first, dis[e.first]});
            }
        }
    }
}
```