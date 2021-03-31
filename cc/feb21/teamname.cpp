/*
	author: Creepysta
	21-02-2021 19:41:46
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e9) + 7;

void solve() {
	int n;
	cin >> n;
	vector<string> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	vector<pair<string, int>> suffixes(n);
	for(int i = 0; i < n; i++) {
		suffixes[i] = {a[i].substr(1), i};
	}
	sort(suffixes.begin(), suffixes.end());
	vector<int> classes(n);
	for(int i = 1; i < n; i++) {
		if(suffixes[i-1].first == suffixes[i].first) 
			classes[suffixes[i].second] = classes[suffixes[i-1].second];
		else
			classes[suffixes[i].second] = 1+classes[suffixes[i-1].second];
	}
	vector<vector<bool>> is_funny(26, vector<bool> (n, false));
	//matches classes of strings and the 1st characters of given words
	for(int i = 0; i < n; i++)
		is_funny[a[i][0] - 'a'][classes[i]] = 1;
#ifdef LOCAL
	cout << "classes: \n";
	for(int i : classes) {
		cout << i << ' ';
	}
	cout << '\n';
	cout << "is_funny: \n";
	for(int i = 0; i < 26; i++) {
		for (int j = 0; j < n; j++) {
			cout << is_funny[i][j] << ' ';
		}
		cout << "\n";
	}
#endif
	int ans = 0;
	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < 26; j++) {
			int cnt01 = 0, cnt10 = 0;
			for(int k = 0; k < n; k++) {
				if(is_funny[i][k] && !is_funny[j][k])
					cnt10++;
				else if(!is_funny[i][k] && is_funny[j][k])
					cnt01++;
			}
			ans += cnt01 * cnt10;
		}
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

