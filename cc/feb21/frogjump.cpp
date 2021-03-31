/*
	author: Creepysta
	21-02-2021 18:04:10
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e9) + 7;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n+1);
	vector<int> l(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	for(int i = 1; i <= n; i++)
		cin >> l[i];
	sort(a.begin(), a.end());
	int ans = 0, curr = 0;
	//cout << a[1].first << ' ' << a[1].second << '\n';
	for(int i = 2; i <= n; i++) {
		if(a[i].second <= max(curr, a[i-1].second)) {
			int step = (max(a[i-1].second, curr)+1 - a[i].second + l[a[i].second]-1) / l[a[i].second];
			int where = a[i].second + l[a[i].second] * step;
			ans += step;
			curr = max(curr, where);
		}
		//cout << a[i].first << ' ' << max(a[i].second,curr)<< '\n';
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
		//cout << "Case #" << tt << ":\n";
		solve();
	}
	return 0;
}

