# 区间DP模板
```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> sum(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
    
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }
    
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            for (int k = l; k < r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + sum[r] - sum[l - 1]);
            }
        }
    }
    
    cout << dp[1][n] << '\n';
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