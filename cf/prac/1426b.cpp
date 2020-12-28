/*
	author: Creepysta
	20-10-2020 09:47:12
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n, m;
	cin >> n >> m;
	bool ok = 0;
	for(int i = 0; i < n; i++) {
		int a1, b1, a2, b2;
		cin >> a1 >> b1 >> a2 >> b2;
		ok |= (b1 == a2);
	}
	ok &= !(m & 1);
	cout << (ok ? "YES" : "NO") << '\n';
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

