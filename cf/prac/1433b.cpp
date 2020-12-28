/*
	author: Creepysta
	21-10-2020 22:17:55
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int i = 0, j = n - 1;
	while(i < n && !a[i]) {
		i++;
	}
	while(j >= 0 && !a[j]) {
		j--;
	}
	int zero = 0;
	//cout << zero << ' ' << i << ' ' << j << endl;
	for(int idx = i; idx <= j; idx++) {
		if(a[idx] == 0)
			zero ++;
	}
	int ans = zero;// + min(i-0, n-1 - j);
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		//cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

