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
		int w = -1 * get<1>(v);
		if(!vis[to]) {
			timer += w;
			ans[to] = timer;
			//printf("%d -> %d (%I64d)\n", u, to, ans[to]);
			dfs(to);
			//bool check = true;
			//for(bool vv : vis)
			//	check &= vv;
			//if(check)
			//	return;
			timer += w;
			//printf("%d -> %d (%I64d)\n", to, u, timer);
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
		g[x].push_back(make_tuple(prior[y], -w, y));
		g[y].push_back(make_tuple(prior[x], -w, x));
	}
	for(int i = 0; i < n; i++) {
		sort(g[i].rbegin(), g[i].rend());
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
