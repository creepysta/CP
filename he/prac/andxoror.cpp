/*
	author: Creepysta
	30-12-2020 05:44:08
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
	vector<vector<int>> bits(32);
	vector<bool> vis(n, false);
	for(int i = 0; i < n; i++) {
		for(int mask = 31; mask >= 0; mask --) {
			if(!vis[i] && a[i] & (1 << mask)) {
				bits[mask].push_back(i);
				vis[i] = 1;
			}
		}
	}
	int small = *max_element(a.begin(), a.end());
	for(int b = 0; b < 32; b++) {

		for(int i = 0; i < n; i++) {


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

