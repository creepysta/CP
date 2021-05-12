/*
	author: Creepysta
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int &i : a)
		cin >> i;
	int q;
	cin >> q;
	auto pos = [&] (const int &x) {
		int ans = -1;
		int l = 0, h = n - 1;
		while(l <= h) {
			int mid = l + (h - l) / 2;
			if(a[mid] >= x) {
				ans = mid;
				h = mid - 1;
			} else
				l = mid + 1;
		}
		if(ans == -1)
			return n;
		return ans;
	};
	sort(a.begin(), a.end());
	while(q--) {
		int left, right;
		cin >> left >> right;
		int li = pos(left);
		int ri = pos(right+1);
		int ans = ri - li;
		cout << ans << ' ';
	}
	cout << '\n';
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

