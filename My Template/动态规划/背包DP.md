# 背包DP模板
```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

// 01背包
void zeroOnePack() {
    int n, W;
    cin >> n >> W;
    vector<int> w(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    
    vector<int> dp(W + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[W] << '\n';
}

// 完全背包
void completePack() {
    int n, W;
    cin >> n >> W;
    vector<int> w(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    
    vector<int> dp(W + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = w[i]; j <= W; j++) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[W] << '\n';
}

// 多重背包（二进制优化）
void multiplePack() {
    int n, W;
    cin >> n >> W;
    vector<int> w, v;
    
    for (int i = 1; i <= n; i++) {
        int wi, vi, ci;
        cin >> wi >> vi >> ci;
        for (int k = 1; k <= ci; k <<= 1) {
            w.push_back(wi * k);
            v.push_back(vi * k);
            ci -= k;
        }
        if (ci) {
            w.push_back(wi * ci);
            v.push_back(vi * ci);
        }
    }
    
    vector<int> dp(W + 1);
    for (int i = 0; i < (int)w.size(); i++) {
        for (int j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[W] << '\n';
}
```