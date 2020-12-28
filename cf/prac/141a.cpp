/*
	author: Creepysta
	15-11-2020 20:59:53
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	vector<int> cnt(26), cnt1(26);
	for(char c : s3) {
		cnt[c-'A'] ++;
	}
	for(string s : {s1, s2}) {
		for(char c : s) {
			cnt1[c - 'A']++;
		}
	}
	for(int i = 0; i < 26; i++) {
		if(cnt[i] != cnt1[i]) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
	return;
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

