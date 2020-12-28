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

const int mod = 1e9 + 7;

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
	string s;
	cin >> s;
	ll n = s.length();
	vector<ll> cnt(26);
	for(char ch : s) {
		cnt[ch-'a']++;
	}
	ll num = fact(n), den = 1LL;
	for(int i : cnt) {
		den = (den * fact(i)) % mod;
	}
	den = power(den, mod - 2);
	ll ans = (num * den) % mod;
	cout << ans << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}

