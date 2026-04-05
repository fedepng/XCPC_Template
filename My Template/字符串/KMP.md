# KMP算法模板

```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

struct KMP {
    string s, p;
    vector<int> nxt;
    
    KMP(string& t, string& pattern) : s(t), p(pattern) {
        nxt.resize(p.size());
        build();
    }
    
    void build() {
        int j = 0;
        for (int i = 1; i < (int)p.size(); i++) {
            while (j > 0 && p[i] != p[j]) j = nxt[j - 1];
            if (p[i] == p[j]) j++;
            nxt[i] = j;
        }
    }
    
    vector<int> search() {
        vector<int> res;
        int j = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            while (j > 0 && s[i] != p[j]) j = nxt[j - 1];
            if (s[i] == p[j]) j++;
            if (j == (int)p.size()) {
                res.push_back(i - p.size() + 2);  // 1-indexed 位置
                j = nxt[j - 1];
            }
        }
        return res;
    }
    
    int count() {
        int res = 0;
        int j = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            while (j > 0 && s[i] != p[j]) j = nxt[j - 1];
            if (s[i] == p[j]) j++;
            if (j == (int)p.size()) {
                res++;
                j = nxt[j - 1];
            }
        }
        return res;
    }
};

void solve() {
    string s, p;
    cin >> s >> p;
    
    KMP kmp(s, p);
    
    vector<int> pos = kmp.search();
    for (int x : pos) {
        cout << x << ' ';
    }
    cout << '\n';
    cout << kmp.count() << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```