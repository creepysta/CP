/*
	author: Creepysta
	19-10-2020 12:23:28
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a[26];
	memset(a, 0, sizeof(a));
	for(char c : s) {
		a[c-'a'] ++;
	}
	if(a[s[n-1]-'a'] < 2) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
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

