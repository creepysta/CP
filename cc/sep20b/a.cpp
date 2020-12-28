/*
	author: Creepysta
	05-09-2020 09:21:53
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
	sort(a.rbegin(), a.rend());
	int ans = 0;
	for(int i = 0; i < n; i++) {
		while(i < n-1 && a[i] == a[i+1])
			i++;
		ans ++;
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

