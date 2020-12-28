#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define ff first
#define ss second
#define endl '\n'

const ll MOD = 1e9 + 7;

ll power(ll a, ll b, ll mod) {
	ll res = 1LL;
	while(b) {
		if (b & 1) res = (res * a % mod) % mod;
		a = (a % mod * a % mod) % mod;
		b >>= 1;
	}
	return res;
}

ll fact(ll a, ll mod) {
	ll f = 1LL;
	while(a) {
		f = (f * (a--) % mod) % mod;
	}
	return f;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}

