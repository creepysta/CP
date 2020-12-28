#include <bits/stdc++.h>
using namespace std;

int maxc = 0;
vector<vector<int>> g;
vector<bool> vis;
vector<bool> canbe;
vector<int> a;

void dfs(int index, int me) {
	vis[index] = 1;
	if(index == me) {
		canbe[me] = 1;
	}
	for (int idx : g[index]) {
		if (!vis[idx]) {
			if(idx == me) {
				canbe[me] = 1;
			}
			dfs(idx, me);
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	a.clear();a.resize(n);
	g.clear();g.resize(n);
	canbe.clear();canbe.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		assert(a[i] != n);
	}
	vis.clear();
	vis.resize(n, false);
	while(m--) {
		int x, y;
		cin >> x >> y;
		x--;y--;
		g[x].push_back(y);
		g[y].push_back(x);
		assert(x != n || y != n);
	}
	for(int i = 0; i < (int) g.size(); i++) {
		cout << i << "-> ";
		for(int gg : g[i]) {
			cout << gg << ' ';
		}
		cout << endl;
	}
	for(int i = 0; i < n; i++) {
		vis.assign(n, false);
		dfs(i, a[i]);
	}
	int ptr = 0, cycle = 0, ans = 0;
	vis.assign(n, false);
	cout << "debug canbe sorted by robot\n";
	for(auto inp : canbe)
		cout << inp << ' ';
	cout << endl;
	while(++ptr <= n) {
		if(vis[ptr] || a[ptr] == ptr) {
			continue;
		}
		int j = a[ptr];
		cycle = 0;
		while(!vis[j]) {
			vis[j] = 1;
			j = a[j];
			cycle++;
		}
		ans += (cycle -1);
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cout << "Case #" << t << ":\n";
		solve();
	}
	return 0;
}
