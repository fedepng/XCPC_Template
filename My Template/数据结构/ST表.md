# ST表解决RMQ问题模板

```cpp
#include<bits/stdc++.h>
#define int long long
#define maxn 200005

const int INF = 1e18;

using namespace std;

int n, q, h[maxn], log[maxn], rmax[maxn][18], rmin[maxn][18];

void init() {
    for (int i = 2; i <= n; i++) log[i] = log[i >> 1] + 1;
    for (int i = 1; i <= n; i++) rmax[i][0] = rmin[i][0] = h[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            rmax[i][j] = max(rmax[i][j - 1], rmax[i + (1 << j - 1)][j - 1]);
            rmin[i][j] = min(rmin[i][j - 1], rmin[i + (1 << j - 1)][j - 1]);
        }
    }
}

int query_max(int l, int r) {
    int len = log[r - l + 1];
    return max(rmax[l][len], rmax[r - (1 << len) + 1][len]); 
}

int query_min(int l, int r) {
    int len = log[r - l + 1];
    return min(rmin[l][len], rmin[r - (1 << len) + 1][len]); 
}
```