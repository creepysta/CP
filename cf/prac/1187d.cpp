/*
 * https://codeforces.com/contest/1187/problem/D
 */
/*
	author: Creepysta
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	unordered_map<int, int> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		m[b[i]]++;
	}
	bool ok = true;
	/*
	for(auto e : m) {
		if(e.second % 2) {
			ok = false;
		}
	}
	bool notyet = false;
	for(int i = 0; i < n; i++) {
		if(!notyet && a[i] > b[i])
			notyet = true;
		if(a[i] < b[i]) {
			if(!notyet)
				ok = false;
		}
	}
	if(ok)
		cout << "YES\n";
	else
		cout << "NO\n";
	*/
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

