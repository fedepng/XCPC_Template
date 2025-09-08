# 基础SPFA模板

```cpp
#include<bits/stdc++.h>
#define int long long
#define maxn 200005

const int INF = 1e18;

using namespace std;

int n, m, dis[maxn];
bool vis[maxn];
vector<pair<int, int>> edges[maxn];

void spfa() {
    queue<int> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0, vis[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        vis[p] = 0;
        for (const auto& e : edges[p]) {
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