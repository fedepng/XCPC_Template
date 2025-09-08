manacher算法模板

```cpp
#include<bits/stdc++.h>
#define int long long
#define maxn 200005

using namespace std;

const int INF = 1e18;

int d[maxn];

void manacher(string s) {
    d[1] = 1;
    for (int i = 2, l, r = 1; i < s.size(); i++) {
        if (i <= r) d[i] = min(d[r + l - i], r - i + 1);
        while (s[i - d[i]] == s[i + d[i]]) d[i]++;
        if (i + d[i] - 1 > r) l = i - d[i] + 1, r = i + d[i] - 1;
    }
}

void init(string& s) {
    string s1 = '$';
    for (int i = 0; i < s.size(); i++) {
        s1 += '#';
        s1 += s[i];
    }
    s1 += '#';
    s = s1;
}
```