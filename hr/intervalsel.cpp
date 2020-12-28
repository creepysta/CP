/*
	author: Creepysta
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for(int i = 0; i < n; i++) 
		cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end());
	int curr = 0, ans = 0;
	auto where = [&] (const pair<int, int> &a, const pair<int, int> &b) {
		if(a[i].second >= b[i].second) 
			return 1;
		return -1;
	}
	stack<pair<int, int>> s;
	for(int i = 0; i < n; i++) {
		s.push(a[i]);
		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

