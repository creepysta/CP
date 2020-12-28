/*
author: Creepysta
 */
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	long long n;
	cin >> n;
	if(n == 0) {
		cout << -1 << ' ' << 1 << '\n';
		return;
	}
	long long l = 0ll, r = 1ll;
	int idx = 0;
	for(int i = 40; i >= 0; i--) {
		if(n & (1ll << (long long) i)) {
			idx = i;
			break;
		}
	}
	r = r << (long long) idx;
	for(int i = 0; i < idx; i++) {
		if((1ll << (long long) i) & n)
			l |= (1ll << (long long) i);
	}
	cout << l << ' ' << r << '\n';
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

