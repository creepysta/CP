/*
	author: Creepysta
	16-11-2020 17:53:03
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e9) + 7;

void solve() {
	int n;
	cin >> n;
	if(n % 4) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for(int i = 1; i <= n/2; i++) {
		cout << 2 * i << ' ';
	}
	for(int i = 1; i < n/2; i++) {
		cout << (2*i - 1) << ' ';
	}
	cout << 3 * (n/2) - 1 << '\n';
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

