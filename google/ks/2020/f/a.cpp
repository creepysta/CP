/*
	author: Creepysta
	27-09-2020 12:09:58
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<pair<int, int>> a(n);
	vector<int> ans(n);
	for(int i = 0; i < n; i++)
		cin >> a[i].first, a[i].second = i+1;
	for(int i = 0; i < n; i++)
		a[i].first /= x;
	sort(a.begin(), a.end(), 
			[&](const pair<int, int> &c, const pair<int, int> &d) {
				return c.first == d.first ? \
					c.second < d.second : c.first < d.first;
			});
	for(auto p : a)
		cout << p.second << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

