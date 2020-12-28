/*
	author: Creepysta
	21-11-2020 13:43:45
*/
#include <bits/stdc++.h>
using namespace std;

// 6 6 -1
// -1 6 
const int MOD = int(1e9) + 7;


void solve() {
	int n, m, s;
	cin >> n >> m;
	vector<vector<int>> g(n);
	vector<bool> vis(n, false);
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x --; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cin >> s;
	queue<int> q;
	q.push(--s);
	vis[s] = 1;
	int lev = q.size(), mul = 1;
	vector<int> ans(n, -1);
	while(!q.empty()) {
		int ver = q.front();
		q.pop();
		// vis[ver] = 1;
		for(int v : g[ver]) {
			if(!vis[v]) {
				q.push(v);
				ans[v] = mul * 6;
				vis[v] = 1;
				// cerr << "DEBUG " << v << endl;
			}
		}
		if(--lev == 0) {
			lev = q.size();
			++mul;
		}
	}
	for(int i = 0; i < n; i++) {
		if(i != s)
			cout << ans[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

