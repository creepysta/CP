/*
	author: Creepysta
	21-10-2020 21:50:50
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int x;
	cin >> x;
	int big = (x%10) - 1;
	int ans = (4 * (4 + 1)) / 2;
	ans *= big;
	int num = 1;
	while(x) {
		x/=10;
		ans += num++;
	}
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

