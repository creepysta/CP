/*
	author: Creepysta
	16-11-2020 22:38:53
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e9) + 7;

void solve() {
	vector<int> a(3);
	for(int &i : a)
		cin >> i;
	sort(a.begin(), a.end());
	int pt = (a[0] + a[2]) / 2;
	int ans = abs(a[0]-pt) + abs(a[1]-pt) + abs(a[2]-pt);
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

