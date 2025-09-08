# 二维Dijkstra模板

```cpp
#include<bits/stdc++.h>
#define int long long
#define maxn 200005

using namespace std;

const int INF = 1e18;

int n, m;
int dis1[maxn], dis2[maxn];
bool vis[maxn];

struct edge {
    int v, w1, w2;
};
vector<edge> edges[maxn];

struct node {
    int p;      
    int d1, d2;
    friend bool operator < (const node& a, const node& b) {
        if (a.d1 != b.d1) return a.d1 > b.d1;
        return a.d2 > b.d2;
    }
};

void dij(int start) {
    priority_queue<node> q;
    memset(dis1, 0x3f, sizeof(dis1));
    memset(dis2, 0x3f, sizeof(dis2));
    dis1[start] = 0;
    dis2[start] = 0;
    q.push({start, 0, 0}); 
    while (!q.empty()) {
        int p = q.top().p;
        q.pop(); 
        if (vis[p]) continue;
        vis[p] = 1;
        for (const edge& e : edges[p]) {
            if (dis1[e.v] > dis1[p] + e.w1) {
                dis1[e.v] = dis1[p] + e.w1;
                dis2[e.v] = dis2[p] + e.w2;
                q.push({e.v, dis1[e.p], dis2[e.p]});
            } else if (dis1[e.v] == dis1[p] + e.w1 && dis2[e.v] > dis1[e.p] + e.w2) {
                dis2[e.v] = dis2[p] + e.w2;
                q.push({e.v, dis1[e.p], dis2[e.p]});
            }
        }
    }
}
```