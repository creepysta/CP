/*
	author: Creepysta
	22-10-2020 07:18:50
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int &i : a)
		cin >> i;
	int big = *max_element(a.begin(), a.end());
	for(int i = 1; i < n-1; i++) {
		if(big == a[i] && (a[i] != a[i-1] || a[i] != a[i+1]) 
			
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

