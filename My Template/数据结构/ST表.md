# ST表解决RMQ问题模板

```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

int n, q;
vector<int> h, lg;
vector<vector<int>> mx, mn;

void init() {
    lg.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    
    int k = lg[n] + 1;
    mx.assign(n + 1, vector<int>(k));
    mn.assign(n + 1, vector<int>(k));
    
    for (int i = 1; i <= n; i++) {
        mx[i][0] = mn[i][0] = h[i];
    }
    
    for (int j = 1; j < k; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int qmax(int l, int r) {
    int len = lg[r - l + 1];
    return max(mx[l][len], mx[r - (1 << len) + 1][len]);
}

int qmin(int l, int r) {
    int len = lg[r - l + 1];
    return min(mn[l][len], mn[r - (1 << len) + 1][len]);
}

void solve() {
    cin >> n >> q;
    h.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    
    init();
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << qmax(l, r) - qmin(l, r) << '\n';
    }
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