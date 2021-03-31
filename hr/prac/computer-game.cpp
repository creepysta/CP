/*
	author: Creepysta
	04-03-2021 09:32:57
*/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int MOD = int(1e9) + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    for(int i = 0, j = 0; i < n && j < n; ) {
        int g = gcd(a[i], b[j]);
        if(g != 1) {
            ans++;
        }
    }	
}

int32_t main() {
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

