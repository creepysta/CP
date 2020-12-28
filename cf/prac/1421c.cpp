/*
	author: Creepysta
	19-10-2020 20:59:28
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	string s;
	cin >> s;
	int big = 1;
	pair<int, int> slr;
	for(int i = 0; i < n; i++) {
		auto one = pal(s, i, i);
		auto two = pal(s, i, i+1);
		int eone = one.second - one.first + 1, etwo = two.second - two.first + 1;
		if(big < max(eone, etwo)) {
			if(eone > etwo) {
				slr = eone;
			} else {
				slr = etwo;
			}
		}
	}
	// R n-1
	// L n
	// L 2
}

pair<int, int> pal(string s, int l, int r) {
	int n = s.length();
	while(l >= 0 && r < n && s[l] == s[r]) {
		l--, r++;
	}
	return {l, r};
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

