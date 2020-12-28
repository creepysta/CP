/*
	author: Creepysta
	04-09-2020 20:06:06
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	long long a, b;
	cin >> a >> b;
	if(a > b)
		swap(a, b);
	long long ans = abs(b-a) / 10;
	a += ans * 10;
	if(a != b)
		ans++;
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

