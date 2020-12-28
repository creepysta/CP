/*
	author: Creepysta
	04-09-2020 20:34:07
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	if(n == 2) {
		cout << x << ' ' << y << '\n';
		return;
	}
	int num = y - x, cd = y - x;
	for(int i = n-1; i > 0; i--) {
		if((y-x) % i == 0) {
			num = i;
			break;
		}
	}
	int rem = n - num - 1;
	cd = (y - x) / num;
	int toleft = x - cd * rem > 0 ? rem : (x - 1) / cd;
	x -= toleft * cd;
	for(int i = 0; i < n; i++) {
		int ai = x + cd * i;
		cout << ai << ' ';
	}
	cout << '\n';
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

