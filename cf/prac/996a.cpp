/*
	author: Creepysta
	15-11-2020 21:10:58
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	int a[] = {1,5,10,20,100};
	int ans = 0;
	int i = 4;
	while(i >= 0 && n) {
		int q = n/a[i];
		if(q) {
			n -= q * a[i];
			ans += q;
		} else {
			i--;
		}
	}
	cout << ans << '\n';
}

int main() {
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

