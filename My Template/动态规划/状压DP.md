# 状态压缩DP模板
```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    // dp[mask] 表示已经选了 mask 集合时的最优值
    vector<int> dp(1 << n, INF);
    dp[0] = 0;
    
    for (int mask = 0; mask < (1 << n); mask++) {
        int i = __builtin_popcount(mask);  // 当前已选人数（第 i 行）
        for (int j = 0; j < n; j++) {
            if (!(mask >> j & 1)) {  // 第 j 列还没选
                int new_mask = mask | (1 << j);
                dp[new_mask] = min(dp[new_mask], dp[mask] + a[i][j]);
            }
        }
    }
    
    cout << dp[(1 << n) - 1] << '\n';
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