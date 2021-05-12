/*
	author: Creepysta
	04-09-2020 17:35:51
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	int l = 0, h = n * max(x, y);
	auto good = [&] (int xx) {
		int time = min(x, y);
		time += (n-1) * x * y / ((double) (x + y));
		return time <= xx;
	};
	/*
	   8 +0		4 +0	5 +0
	   7 +3		3 +1	4 +1
	   5 +4		1 +1	3 +2
	   3 +4		0 +1	1 +1
	   1 +4
	   0 +3

	 */
	int ans = 0;
	while(l <= h) {
		int mid = l + (h - l) / 2;
		if(good(mid)) {
			h = mid - 1;
			ans = mid;
		} else
			l = mid + 1;
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
