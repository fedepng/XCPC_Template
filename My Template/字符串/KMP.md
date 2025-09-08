KMP算法查询字符串模板

```cpp
#include<bits/stdc++.h>
#define int long long
#define maxn 200005

using namespace std;

const int INF = 1e18;

string s1, s2;
int ne[maxn];

void kmp() {
    for (int i = 1, j; i < s2.size(); i++) {
        while (j > 0 && s2[i] != s2[j]) j = ne[j - 1];
        if (s2[i] == s2[j]) j++;
        ne[i] = j;
    }
    for (int i = 0, j; i < s1.size(); i++) {
        while (j > 0 && s1[i] != s2[j]) j = ne[j - 1];
        if (s1[i] == s2[j]) j++;
        if (j == s2.size()) {
            cout << i + 1 - s2.size() + 1 << ' ';
            j = ne[j - 1];
        }
    }
}