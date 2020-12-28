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

void solve() {
	ll sum;
	cin >> sum;
	vector<ll> dp(sum+1, 0);
	for(int i = 1; i <= sum; i++) {
		for(int j = 1; j <= 6; j++) {
			if(i - j > 0) {
				dp[i] += dp[i-j];
				dp[i] = (dp[i]) % MOD;
			} else if(i == j) {
				dp[i] = (dp[i] + 1) % MOD;
			}
		}
	}
	cout << dp[sum] << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll t=1;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}

