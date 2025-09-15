```cpp
#include<bits/stdc++.h>
#define int long long
#define maxn 200005
#define inf 0x3f3f3f3f

using namespace std;

int n, m, s, t;
struct edge{
    int to;
    int cap;
    int rev;
};
vector<edge> edges[maxn];
int pre_v[maxn];
int pre_e[maxn];
int min_flow[maxn];

bool bfs() {
    memset(pre_v, -1, sizeof(pre_v));
    pre_v[s] = s;
    queue<int> q;
    q.push(s);
    min_flow[s] = inf;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < edges[u].size(); i++) {
            edge& e = edges[u][i];
            if (pre_v[e.to] == -1 && e.cap > 0) {
                pre_v[e.to] = u;
                pre_e[e.to] = i;
                min_flow[e.to] = min(min_flow[u], e.cap);
                q.push(e.to);
                if (e.to == t) return 1;
            }
        }
    }
    return 0;
}

int max_flow() {
    int res = 0;
    while (bfs()) {
        int f = min_flow[t];
        res += f;
        int v = t;
        while (v != s) {
            int u = pre_v[v];
            int e = pre_e[v];
            edges[u][e].cap -= f;
            edges[v][edges[u][e].rev].cap += f;
            v = u;
        }
    }
    return res;
}

void add_edge(int u, int v, int w) {
    edges[u].push_back({v, w, (int) (edges[v].size())});
    edges[v].push_back({u, 0, (int) (edges[u].size() - 1)});
}

signed main() {
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    cout << max_flow() << endl;
}
```