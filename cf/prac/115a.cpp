/*
	author: Creepysta
	06-09-2020 11:38:47
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int grps = 0;
void dfs(int u, const vector<vector<int>> &a, int level) {
	grps = max(grps, level);
	for(int child : a[u]) {
		dfs(child, a, level + 1);
	}
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> p(n+1);
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if(x != -1)
			p[x].push_back(i);
		else
			p[0].push_back(i);
	}
	for(int i = 0; i < (int) p[0].size(); i++) {
		dfs(p[0][i], p, 1);
	}
	
	for(int i = 0; i < (int) p.size(); i++) {
		cout << i << ' ';
		for(int pp : p[i]) {
			cout << pp << ' ';
		}
		cout << endl;
	}
	
	cout << grps << '\n';
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

