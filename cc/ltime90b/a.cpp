/*
	author: Creepysta
	29-11-2020 21:57:41
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e9) + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int &i : a)
		cin >> i;
	int left = 0, ans = 0;
	for(int i = 0; i < n; i++) {
		left += a[i];
		if(left == 0) {
			cout << ans << '\n';
			return;
		}
		left --;
		ans ++;
	}
	ans += left;
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

