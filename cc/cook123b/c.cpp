/*
	author: Creepysta
	19-10-2020 13:21:43
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> g;
vector<int> val;

void dfs(int u, int level, int parent) {
	if(level & 1)
		val[u] = 1;
	else
		val[u] = 2;
	//vis[u] = true;
	for(int v: g[u]) {
		//if(!vis[v])
		if(parent != v)
			dfs(v, level+1, u);
	}
}

void solve() {
	int n;
	cin >> n;
	g.clear();g.resize(n);
	val.assign(n, 0);
	for(int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0, 0, -1);
	for(int v : val)
		cout << v << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		//cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

