/*
	author: Creepysta
	24-02-2021 19:33:30
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e9) + 7;

void solve() {
	int n, m, op, x, y;
	cin >> n >> m;
	vector<pair<int, int>> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i].second;
		a[i].first = i;
	}
	for(int i = 1; i < n; i++)
		a[i].first += a[i-1].first;
	for(int i = 0; i < m; i++) {
		cin >> op >> x >> y;
		x--, y--;
		if(op) {
			a[x].first -= n;
			a[y].first = y+1 == n ? a[y].first : a[y].first - n;
		} else {
			a[x].first += n;
			a[y].first = y+1 == n ? a[y].first : a[y].first + n;
		}
	}
	for(auto p : a)
		cout << p.first << ' ';
	cout << "\n";
	sort(a.begin(), a.end());
	int ans = abs(a[0].second - a[n-1].second);
	cout << ans << '\n';
	for(auto p : a)
		cout << p.first << ' ';
	cout << "\n";
	for(auto p : a)
		cout << p.second << ' ';
	cout << '\n';
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

