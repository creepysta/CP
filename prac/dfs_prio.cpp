#include <bits/stdc++.h>
using namespace std;

vector<vector<tuple<int, int, int>>> g;
vector<bool> vis;
vector<int64_t> ans;
int64_t timer;

void dfs(int u) {
	vis[u] = true;
	for(auto v : g[u]) {
		int to = get<2>(v);
		int w = get<1>(v);
		if(!vis[to]) {
			timer += w;
			ans[to] = timer;
			dfs(to);
			timer += w;
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	n++;
	g.resize(n);
	vis.assign(n, false);
	ans.assign(n, 0);
	vector<int> prior(n);
	for(int i = 1; i < n; i++) {
		cin >> prior[i];
	}
	for(int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		g[x].push_back(make_tuple(-prior[y], w, y));
		g[y].push_back(make_tuple(-prior[x], w, x));
	}
	for(int i = 0; i < n; i++) {
		sort(g[i].begin(), g[i].end());
	}
	dfs(0);
	for(int64_t i : ans)
		cout << i << ' ';
	cout << '\n';
}

int main() {
	int t = 1;
	//cin >> t;
	while(t--) {
		timer = 0;
		vis.clear();
		g.clear();
		ans.clear();
		solve();
	}
	return 0;
}
