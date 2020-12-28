/*
	author: Creepysta
	04-09-2020 17:01:41
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	auto good = [&] (double x) {
		int s = 0;
		for(int i = 0; i < n; i++)
			s += floor(a[i] / x);
		return s >= k;
	};
	const int rep = 100;
	const int eps = 1e-9;
	double ans = 0.;
	double l = 0., r = 1e8;
	cout << fixed << setprecision(20);
	for(int i = 1; i <= rep; i++) {
	// while(r - l > eps) {
		double m = (l + r) / 2.;
		if(good(m)) {
			ans = m;
			l = m;
		} else
			r = m;
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

