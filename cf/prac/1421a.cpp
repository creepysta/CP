/*
	author: Creepysta
	19-10-2020 19:11:19
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int a, b;
	cin >> a >> b;
	int ans = 0;
	for(int i = 0; i < 32; i++) {
		if(((a & (1 << i)) && (b & (1 << i))) || (!(a & (1 << i)) && !(b & (1 << i)))) {
			continue;
		} else {
			ans |= 1 << i;
		}
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

