
/*
	author: Creepysta
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int &i : a)
		cin >> i;
	while(q--) {
		int x;
		cin >> x;
		int l = 0, h = n-1;
		int ans = -1;
		while(l <= h) {
			int mid = l + (h - l) / 2;
			if(a[mid] >= x) {
				ans = mid;
				h = mid - 1;
			} else
				l = mid + 1;
		}
		if(ans == -1) {
			cout << n+1 << '\n';
			continue;
		}
		cout << ans+1 << '\n';
	}
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

