/*
	author: Creepysta
	22-10-2020 12:27:24
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int & i: a)
		cin >> i;
	vector<pair<int, int>> e;
	vector<bool> vis(n);
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if(!vis[j] && a[i] != a[j]) {
				e.push_back({i + 1, j + 1});
				vis[j] = 1;
			}
			if(e.size() == n-1)
				break;
		}
		if(e.size() == n-1)
			break;
	}
	if(e.size() < n-1)
		cout << "NO\n";
	else {
		cout << "YES\n";
		for(auto pp : e) {
			cout << pp.first << ' ' << pp.second << '\n';
		}
	}
		
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

