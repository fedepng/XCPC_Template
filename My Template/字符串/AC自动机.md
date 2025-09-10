# AC自动机模板

```cpp
#include<bits/stdc++.h>
#define int long long
#define maxn 200005

const int INF = 1e18;

using namespace std;

int trie[maxn][26], cnt[maxn], tot, ne[maxn];

void insert(string s) {
    int u = 0;
    for (int i = 0; i < s.size(); i++) {
        int a = s[i] - 'a';
        if (trie[u][a] == 0) trie[u][a] = ++tot;
        u = trie[u][a];
    }
    cnt[u]++;
}

void build() {
    queue<int> q;
    for (int i = 0; i < 26; i++) if (trie[0][i]) q.push(trie[0][i]);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            int v = trie[u][i];
            if (v) ne[v] = trie[ne[u]][i], q.push(v);
            else trie[u][i] = trie[ne[u]][i];
        }
    }
}

int query(string s) {
    int ans = 0;
    for (int i = 0, k = 0, k < s.size(); k++) {
        i = trie[i][s[k] - 'a'];
        for (int j = i; j && cnt[j] != -1; j = ne[j]) {
            ans += cnt[j], cnt[j] = -1;
        }
    }
    return ans;
}
```