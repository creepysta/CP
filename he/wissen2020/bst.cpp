/*
	author: Creepysta
	14-12-2020 08:07:07
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e9) + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	stack<int> small, big;
	vector<int> cs(n), cb(n);
	cs[0] = 0, cb[n-1] = 0;
	small.push(a[0]), big.push(a[n-1]);
	for(int i = 1; i < n; i++) {
		small.push(a[i]);
		while(!small.empty() && small.top() > a[i])
			small.pop();
		cs[i] = small.size();
	}
	for(int i = n-2; i >= 0; i--) {
		big.push(a[i]);
		while(!big.empty() && big.top() < a[i])
			big.pop();
		cb[i] = big.size();
	}
	vector<int> ans(n);
	for(int i = 0; i < n; i++) {
		ans[i] = max(cs[i], cb[i]);
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
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

