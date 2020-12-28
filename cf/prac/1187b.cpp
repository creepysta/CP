/*
	author: Creepysta
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int q;
	cin >> q;
	vector<vector<int>> v(26);
	for(int i = 0; i < n; i++)
		v[s[i]-'a'].push_back(i+1);
	while(q--) {
		vector<int> cnt(26);
		string t;
		cin >> t;
		for(char c : t)
			cnt[c-'a']++;
		int ans = -1;
		for(int i = 0; i < 26; i++) {
			if(cnt[i])
				ans = max(ans, v[i][cnt[i]-1]);
		}
		cout << ans << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

