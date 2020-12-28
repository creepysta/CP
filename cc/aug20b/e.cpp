#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve() {
	int n, k;
	cin >> n >> k;
	const int inf = 1e9 + 5;
	const int nax = 1e5 + 5;
	vector<int> a(n), cnt(nax, 0), dp(nax, inf);
	for(int &i : a) 
		cin >> i;
	dp[0] = 0;
	for(int i = 0; i < n; i++) {
		fill(cnt.begin(), cnt.end(), 0);
		for(int j = i; j < n; j++) {
			cnt[a[j]]++;
			int g = 0;
			for(int f = 1; f <= 100; f++)
				g += cnt[f] < 2 ? 0 : cnt[f];
			dp[j + 1] = min(dp[i] + g + k , dp[j + 1]);
		}
	}
	cout << dp[n] << '\n';
	return;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}
