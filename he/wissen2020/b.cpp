/*
	author: Creepysta
	30-12-2020 06:45:41
*/
#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

const int MOD = 998244353;

/*	a = 5 3 2
 *	k = 2:	5 5 5 5 3 3 5 3 2
 *	k = 3:	5 5 5 5 5 5 5 5 5
 *			5 5 5 5 3 3 5 3 3
 *	a = 5 5 2
 *	k = 2:	5 5 5 5 5 5 5 5 2
 *	k = 3:	5 5 5 5 5 5 5 5 5
 *			5 5 5 5 5 5 5 5 5
 *			5 5 5 5 5 5 5 5 2
 *	
 * 9 - 4
 * 4 - 1
 * 1 - 0
 *
 * 27 - 8
 * 8 - 1
 * 1 - 0
 */

ll pow(ll a, ll b) {
	if(a == 0)
		return 0;
	ll result = 1;
	while(b) {
		if(b & 1) result = (result * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return result;
}

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a.rbegin(), a.rend());
	ll ans = 0;
	for(ll i = 0; i < n; i++) {
		ll rep = pow(n-i, k) - pow(n-i-1, k);
		if (rep < 0)
			rep += MOD;
		ans += (a[i] * rep) % MOD;
		cout << a[i] << '*' << rep << endl;
	}
	cout << ans << '\n';
}

int32_t main() {
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

