/*
	author: Creepysta
	26-09-2020 01:01:56
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int m;
	cin >> m;
	int big = m, small = 1;
	string s;
	cin >> s;
	cout << "debug: " << s << '\n';
	if (s[m-2] == '0')
		s += "0";
	else
		s += "1";
	vector<int> ans(m);
	int fzero = -1;
	for(int i = 0; i < m; i++) {
		if(s[i] == '0') {
			ans[i] = big--;
			fzero = i;
			break;
		}
	}
	for(int i = fzero - 1; i >= 0; i--)
		ans[i] = big--;
	for(int i = fzero + 1; i < m; ) {
		for(; i < m && s[i] == '0'; i++) {
			ans[i] = big--;
		}
		small = big;
		int j;
		for(j = i; j < m && s[j] == '1'; j++)
			small--;
		while(i < j)
			ans[i++] = ++small;
	}
	for(int i : ans)
		cout << i << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		solve();
	}
	return 0;
}

