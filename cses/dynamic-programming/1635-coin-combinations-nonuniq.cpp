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
const ll MAX = 1e9 + 5;

/*
coins:			2 3 5
sum:			0 1 2 3 4 5 6 7 8 9
sum-coins[j]+1	0 0 1 3 

 */
void solve() {
	ll n, sum;
	cin >> n >> sum;
	vector<ll> coins(n), dp(sum+1, 0ll);
	for(ll &i : coins)
		cin >> i;
	for(ll i = 1; i <= sum; i++) {
		for(ll j = 0; j < n; j++) {
			if(coins[j] == i)
				dp[i] = (dp[i] + 1) % MOD;
			if(coins[j] < i)
				dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
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

