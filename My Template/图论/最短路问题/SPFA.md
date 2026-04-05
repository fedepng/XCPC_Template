# 基础SPFA模板

```cpp
#include<bits/stdc++.h>
#define int long long

const int INF = 1e18;

using namespace std;

int n, m;
vector<int> dis;
vector<bool> vis;
vector<vector<pair<int, int>>> edges;

void spfa() {
    queue<int> q;
    dis.assign(n, INF);
    dis[0] = 0, vis[0] = 1;
    q.push(0);
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        vis[p] = 0;
        for (auto& e : edges[p]) {
            if (dis[e.first] > dis[p] + e.second) {
                dis[e.first] = dis[p] + e.second;
                if (!vis[e.first]) {
                    vis[e.first] = 1;
                    q.push(e.first);
                }
            }
        }
    }
}
```