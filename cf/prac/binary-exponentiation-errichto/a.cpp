/*
	author: Creepysta
	29-01-2021 08:57:25
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e9) + 7;

void solve() {
	int n;
	double p;
	cin >> n >> p;
	double prob = 1.0;
	while(n) {
		if(n & 1)
			prob = prob * (1.0 - p) + (1.0 - prob) * p;
		p = (1.0-p) * p + p * (1.0-p);
		n >>= 1;
	}
	cout << setprecision(10) << fixed;
	cout << prob << '\n';
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

