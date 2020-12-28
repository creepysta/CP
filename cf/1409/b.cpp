/*
	author: Creepysta
	04-09-2020 20:25:33
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

ll calc(ll a, ll b, ll x, ll y, ll n) {
	ll na = max(x, a - n);
	n = n - a + na;
	ll nb = max(y, b - n);
	return na * nb;
}

void solve() {
	ll a, b, x, y, n;
	cin >> a >> b >> x >> y >> n;
	cout << min(calc(a, b, x, y, n), calc(b, a, y, x, n)) << '\n';
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

