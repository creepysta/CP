/*
	author: Creepysta
	01-12-2020 21:38:35
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e9) + 7;

void solve() {
	int n, k;
	cin >> n >> k;
	int a = n - 1; // we are constrained by a < b
	int max = 0;
	while(a-- > 0) {
		for(int b = a + 1; b <= n; b++) {
			int test = a & b;
			if(test < k && test > max) {
			//if(test < k) {
				max = test;
				// max = std::max(test, max);
			}
		}
	}
	cout << max << '\n';
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

