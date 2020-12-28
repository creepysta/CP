/*
	author: Creepysta
	16-11-2020 18:24:20
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e9) + 7;

void solve() {
	vector<int> a(5);
	for(int &i : a)
		cin >> i;
	sort(a.begin(), a.begin() + 3);
	sort(a.begin() + 3, a.end());
	int sum = 0;
	for(int i = 0; i < 3; i++)
		sum += a[i];
	sum = sum - a[3] - a[4];
	if(sum != 0)
		cout << "NO\n";
	else if (a[0] > a[3] || a[1] > a[4]) {
		cout  << "NO\n";
	} else
		cout << "YES\n";
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

