/*
	author: Creepysta
	20-10-2020 09:38:49
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n, x;
	cin >> n >> x;
	if(n <= 2) {
		cout << 1 << '\n';
		return;
	}
	n-=2;
	int ans = 0;
	if(n) ans +=1;
	ans += ceil(n / (double)x);
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

