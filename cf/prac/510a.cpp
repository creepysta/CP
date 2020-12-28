/*
	author: Creepysta
	15-11-2020 21:55:20
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n, m;
	cin >> n >> m;
	string top(m, '#');
	string mid(m-1, '.');
	n--;
	for(int i = 0; i < n/2; i++) {
		cout << top << '\n';
		if(i%2)
			cout << ("#" + mid) << '\n';
		else
			cout << (mid + "#") << '\n';
	}
	cout << top << '\n';
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

