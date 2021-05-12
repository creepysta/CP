/*
	author: Creepysta
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
long long n, h, w;

inline bool good(long long x) {
	return (x/h) * (x/w) >= n;
}

void solve() {
	cin >> w >> h >> n;
	long long low = 0, high = 1ll, mid;
	long long ans = 0;
	while(!good(high))
		high <<= 1ll;
	while(low <= high) {
		mid = low + (high - low) / 2ll;
		if(good(mid)) {
			ans = mid;
			high = mid - 1;
		} else
			low = mid + 1;
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

