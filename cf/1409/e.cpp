/*
	author: Creepysta
	05-09-2020 08:16:35
*/
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long

const int MOD = 1e9 + 7;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i].ff;
	for(int i = 0; i < n; i++)
		cin >> a[i].ss;
	sort(a.begin(), a.end());
	int j = n-1;
	vector<int> l(n), r(n);
	for(int i = n - 1; i >= 0; i--) {
		while(a[j].ff - a[i].ff > k)
			j--;
		r[i] = j - i + 1;
		if(i + 1 < n)
			r[i] = max(r[i], r[i + 1]);
	}
	//for(int i : r)
	//	cerr << i << ' ';
	//cerr << '\n';
	j = 0;
	for(int i = 0; i < n; i++) {
		while(a[i].ff - a[j].ff > k)
			j++;
		l[i] = i - j + 1;
		if(i > 0)
			l[i] = max(l[i], l[i - 1]);
	}
	//for(int i : l)
	//	cerr << i << ' ';
	//cerr << '\n';
	int ans = 1;
	for(int i = 0; i < n - 1;i ++)
		ans = max(ans, r[i+1] + l[i]);

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

