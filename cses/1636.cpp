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
	ll n, sum;
	cin >> n >> sum;
	vector<ll> coins(n);
	for(ll &i : coins)
		cin >> i;
	sort(coins.begin(), coins.end());
	/*
	vector<vector<ll>> dp(n + 1, vector<ll> (sum+1, 0));
	for(ll i = 0; i <= n; i++) {
		dp[i][0] = 1ll;
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= sum; j++) {
			ll x = i > 0 ? dp[i-1][j] : 0ll;
			ll y = coins[i-1] <= j ? dp[i][j-coins[i-1]] : 0ll;
			dp[i][j] = (x + y) % MOD;
		}
	}*/
	/*
	for(auto dd : dp) {
		for(ll ddd :dd)
			cout << ddd << ' ';
		cout << endl;
	}
	*/
	//cout << dp[n][sum] << endl;
	vector<ll> dp(sum+1, 0);
	dp[0] = 1;
	for(ll i = 0; i < n; i++) {
		for(ll j = coins[i]; j <= sum; j++) {
			dp[j] += dp[j-coins[i]];
			dp[j] %= MOD;
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

