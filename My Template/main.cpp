#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
struct node {
    int a, b, w;
    vector<int> masks;
};
vector<vector<set<int, greater<int>>>> v(4, vector<set<int, greater<int>>> (4));
vector<node> vn;
vector<bool> vis;
int res = 0;

int getIndex(int s1, int s2) {
    if (s1 == 1 && s2 == 1) return 0;
    if (s1 == 1 && s2 == 2) return 1;
    if (s1 == 1 && s2 == 3) return 2;
    if (s1 == 2 && s2 == 2) return 3;
    if (s1 == 2 && s2 == 3) return 4;
    if (s1 == 3 && s2 == 3) return 5;
    return -1;
}

vector<int> getMasks(int w, int h) {
    vector<int> masks;
    for (int x = 0; x + w <= 3; ++x) {
        for (int y = 0; y + h <= 3; ++y) {
            int mask = 0;
            for (int i = 0; i < w; ++i) {
                for (int j = 0; j < h; ++j) {
                    int cell = (y + j) * 3 + (x + i);
                    mask |= (1 << cell);
                }
            }
            masks.push_back(mask);
        }
    }
    return masks;
}

void dfs(int mask, int val, int start) {
    res = max(res, val);
    for (int i = start; i < vn.size(); ++i) {
        if (vis[i]) continue;
        for (int m : vn[i].masks) {
            if ((mask & m) == 0) {
                vis[i] = true;
                dfs(mask | m, val + vn[i].w, i + 1);
                vis[i] = false;
            }
        }
    }
}

void solve() {
    cin >> n;
    vn.clear();
    res = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            v[i][j].clear();
    for (int i = 0; i < n; ++i) {
        int a, b, c; cin >> a >> b >> c;
        if (a > b) swap(a, b);
        v[a][b].insert(c);
    }
    int ti = 0;
    for (auto i : v[1][1]) {
        vn.push_back({1, 1, i, getMasks(1, 1)});
        ti++;
        if (ti == 9) break;
    }
    ti = 0;
    for (auto i : v[1][2]) {
        vn.push_back({1, 2, i, getMasks(1, 2)});
        ti++;
        if (ti == 4) break;
    }
    ti = 0;
    for (auto i : v[1][3]) {
        vn.push_back({1, 3, i, getMasks(1, 3)});
        ti++;
        if (ti == 3) break;
    }
    ti = 0;
    for (auto i : v[2][2]) {
        vn.push_back({2, 2, i, getMasks(2, 2)});
        ti++;
        if (ti == 1) break;
    }
    ti = 0;
    for (auto i : v[2][3]) {
        vn.push_back({2, 3, i, getMasks(2, 3)});
        ti++;
        if (ti == 1) break;
    }
    ti = 0;
    for (auto i : v[3][3]) {
        vn.push_back({3, 3, i, getMasks(3, 3)});
        ti++;
        if (ti == 1) break;
    }
    vis.assign(vn.size(), false);
    dfs(0, 0, 0);
    cout << res << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}