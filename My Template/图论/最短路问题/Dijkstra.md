# 基础Dijkstra模板

```cpp
#include<bits/stdc++.h>
#define int long long

const int INF = 1e18;

using namespace std;

int n, m;
vector<int> dis;
vector<vector<pair<int, int>>> edges;

struct node{
    int p, dis;
    friend bool operator < (node& a, node& b) {
        return a.dis > b.dis;
    }
};

void dij() {
    priority_queue<node> q;
    dis.assign(n, INF);
    dis[0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        int p = q.top().p, d = q.top().dis;
        q.pop();
        if (d > dis[p]) continue;
        for (const auto& e : edges[p]) {
            if (dis[e.first] > dis[p] + e.second) {
                dis[e.first] = dis[p] + e.second;
                q.push({e.first, dis[e.first]});
            }
        }
    }
}
```