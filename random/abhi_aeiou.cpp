/*
	author: Creepysta
	19-02-2021 23:53:23
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int MOD = int(1e9) + 7;
// a, e, i, o, u
// 0, 1, 2, 3, 4
// a -> e, o
// e, o, u -> i
// i -> a, e, o, u
void solve() {
	int n;
	cin >> n;
	int dp[n+1][5];
	memset(dp, 0, sizeof(dp));
	// stores directed edges between chars
	vector<vector<int>> e {
/*a*/	{1, 3},
/*e*/	{2},
/*i*/	{0, 1, 3, 4},
/*o*/	{2},
/*u*/	{2},
	};
	for(int i = 0; i < 5; i++)
		dp[1][i] = 1;
	// dp[i][j] : path of length i ending with j char
	for(int i = 1; i < n; i++) {
		for(int u = 0; u < 5; u++) {
			for(int v : e[u])
				dp[i+1][v] = (dp[i+1][v] + dp[i][u]) % MOD;
		}
	}
	int ans = 0;
	for(int i = 0; i < 5; i++)
		ans = (ans + dp[n][i]) % MOD;
	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

/*
 * docs:https://www.geeksforgeeks.org/count-all-possible-n-length-vowel-permutations-that-can-be-generated-based-on-the-given-conditions/ 
 * */

