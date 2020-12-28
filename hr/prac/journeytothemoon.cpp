/*
    author: Creepysta
    19-11-2020 20:46:01
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e9) + 7;

vector<vector<int>> g;
vector<bool> vis;
int comps;
vector<int> siz;

void dfs(int u) {
    vis[u] = 1;
    comps ++;
    for(int v : g[u]) {
        if(!vis[v])
            dfs(v);
    }
}

uint64_t process(const vector<int>& v) {
    uint64_t prod = 1, sum = 0, fin = 0;
    vector<uint64_t> prefix(v.size());
    prefix[0] = v[0];
    for(size_t i = 1; i < v.size(); i++) {
        prefix[i] = prefix[i-1] + (uint64_t) v[i];
    }
    for(size_t i = 1; i < v.size(); i++) {
        prod = v[i];
        sum = prefix[i-1];
        fin += prod * sum;
    }
    return fin;
}

void solve() {
    int n, p;
    cin >> n >> p;
    g.clear(); g.resize(n);
    vis.clear(); vis.assign(n, 0);
    siz.clear();
    while(p--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            comps = 0;
            dfs(i);
            siz.push_back(comps);
        }
    }
    uint64_t ans = process(siz);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    for(int tt = 1; tt <= t; tt++) {
        // cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}

