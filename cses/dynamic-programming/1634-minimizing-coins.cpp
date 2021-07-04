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
void solve() {
	ll n, sum;
	cin >> n >> sum;
	vector<ll> coins(n);
	for(ll &i : coins)
		cin >> i;
	vector<ll> dp(sum+1, MAX);
	dp[0] = 0;
	for(ll i = 1; i <= sum; i++) {
		for(ll j = 0; j < n; j++) {
			if(i == coins[j])
				dp[i] = 1ll;
			else if(coins[j] <= i) {
				dp[i] = min(dp[i-coins[j]] + 1, dp[i]);
			}
		}
		dp[i] %= MOD;
	}
	if(dp[sum] == MAX)
		cout << -1 << endl;
	else
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

