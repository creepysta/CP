/*
	author: Creepysta
	15-11-2020 22:33:44
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	int x;
	cin >> x;
	int mi = x, ma = x;
	int ans = 0;
	for(int i = 1; i < n; i++) {
		cin >> x;
		if(x > ma) {
			ans ++;
			ma = x;
		} else if(x < mi) {
			ans++;
			mi = x;
		}
	}
	cout << ans << '\n';
	
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

