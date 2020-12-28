/*
	author: Creepysta
	16-11-2020 22:33:53
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e9) + 7;

void solve() {
	int n, x, sum = 0;
	cin >> n;
	int me = 0;
	for(int i = 0; i < n; i++) {
		cin >> x;
		sum += x;
		me = min(sum, me);
	}
	cout << abs(me) << '\n';
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

