/*
	author: Creepysta
	18-10-2020 11:06:24
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n, k, x, y;
	cin >> n >> k >> x >> y;
	int prev = x;
	while(true) {
		x = (x + k) % n;
		if(x == y) {
			cout << "YES\n";
			return;
		}
		if (x == prev) {
			cout << "NO\n";
			return;
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

