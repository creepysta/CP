#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define ff first
#define ss second
#define endl '\n'

const int mod = 1e9 + 7;
const int nax = 1e6 + 1;
ll factorials[nax];

ll fact(ll n) {
	ll f = 1LL;
	while(n) {
		f *= n--;
		f %= mod;
	}
	return f;
}

ll power(ll a, ll b) {
	ll res = 1LL;
	while(b) {
		if(b&1) res = (res * a) % (ll) mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}

void solve() {
	int a, b;
	cin >> a >> b;
	/*
	   ll num = fact(a), den = (fact(a-b) * fact(b)) % mod;
	   den = power(den, mod - 2);
	   ll ans = (num * den) % mod;
	 */
	ll num = factorials[a], den = (factorials[a-b] * factorials[b]) % mod;
	den = power(den, mod - 2);
	ll ans = (num * den) % mod;
	cout << ans << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	factorials[0] = 1;
	for(ll i = 1; i <= nax; i++) {
		factorials[i] = (i * factorials[i-1]) % mod;
	}
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}

