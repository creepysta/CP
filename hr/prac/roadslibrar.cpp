#include <bits/stdc++.h>
using namespace std;

vector<vector<uint64_t>> g;
vector<uint64_t> comps;
vector<bool> visited;
uint64_t n, m, lib, road;

uint64_t process(uint64_t n) {
    return min(n * lib, lib + (n-1) * road);
    // uint64_t check, optcheck = uint64_t(1e9) + 5;
    // for(uint64_t i = 1; i <= n; i++) {
    //     check = lib * i + road * (n-i);
    //     optcheck = min(check, optcheck);
    // }
    // return optcheck;
}

void dfs(uint64_t u) {
    visited[u] = true;
    comps.push_back(u);
    for(uint64_t v : g[u]) {
        if(!visited[v])
            dfs(v);
    }
}

void solve() {
    cin >> n >> m >> lib >> road;
    g.resize(n);
    visited.resize(n);
    for(uint64_t i = 0; i < m; i++) {
        uint64_t x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    uint64_t ans = 0;
    for(uint64_t i = 0; i < n; i++) {
        if(!visited[i]) {
            comps.clear();
            dfs(i);
            ans += process(comps.size());      
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    int T;
    cin >> T;
    while(T--) {
        g.clear();
        visited.clear();
        comps.clear();
		chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
        solve();
		chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
		chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
		//cout << "Time taken: " << time_span.count() << " seconds" << '\n';
    }
    return 0;
}

