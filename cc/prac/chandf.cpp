/*
	author: Creepysta
	24-01-2021 12:44:35
*/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int MOD = int(1e9) + 7;
void solve() {
	int x, y, l, r;
	cin >> x >> y >> l >> r;
	auto f = [&](int z) {
		return (x & z) * (y & z);
	};
	cout << x << ' ' << y << ' ' << l << ' ' << r << '\n';
	int ans = 0, z = r, curr = r, now = f(z);
	auto upd = [&]() {
		int got = f(curr);
		if(now > got || (got == now) && curr < z) {
			z = curr;
			now = got;
		}
	};
	for(int i = 62; i >= 0; i--) {
		int m = 1ll << i;
		if(m & curr) {
		}
	}
	cout << ans << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

