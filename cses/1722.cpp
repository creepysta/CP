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

vector<vector<ll>> multiply(vector<vector<ll>> dp, vector<vector<ll>> mul) {
	vector<vector<ll>> res(2, vector<ll> (2, 0LL));
	for(ll i = 0; i < 2; i++) {
		for(ll j = 0; j < 2; j++) {
			for(ll k = 0; k < 2; k++) {
				res[i][j] += (dp[i][k] * mul[k][j]) % mod;
				res[i][j] %= mod;
			}
		}
	}
	return res;
}

ll power(ll n) {
	vector<vector<ll>> a {{0,1}, {1, 1}}, res {{0,1}, {1, 1}};
	while(n) {
		if(n & 1) res = multiply(res, a);
		a = multiply(a, a);
		n >>= 1;
	}
	return res[0][0];
}

void solve() {
	ll n;
	cin >> n;
	ll ans = power(n);
	cout << ans << endl;
	return;
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

