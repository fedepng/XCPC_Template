# 树上DP模板
```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

int n;
vector<vector<int>> g;
vector<vector<int>> dp;  // dp[u][0/1] 表示选/不选 u 的最大价值
vector<int> val;

void dfs(int u, int fa) {
    dp[u][0] = 0;           // 不选 u
    dp[u][1] = val[u];      // 选 u
    
    for (int v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

void solve() {
    cin >> n;
    g.resize(n + 1);
    dp.assign(n + 1, vector<int>(2));
    val.resize(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(1, -1);
    cout << max(dp[1][0], dp[1][1]) << '\n';
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