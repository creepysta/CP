/*
	author: Creepysta
	15-11-2020 22:33:44
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	vector<int> a(4);
	for(int &i : a)
		cin >> i;
	sort(a.begin(), a.end());
	for(int i : {0, 1, 2}) {
		cout << a[3] - a[i] << ' ';
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

