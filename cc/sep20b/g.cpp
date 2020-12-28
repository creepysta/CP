/*
	author: Creepysta
	08-09-2020 17:44:09
*/
// candies
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int64_t k;
void solve() {
	int64_t n;
	cin >> n;
	vector<bool> ans;
	int64_t sum = 2e18 + 1;
	for(int64_t mask = 1; mask < (1 << n); mask++) {
		int64_t s1 = 0, s2 = 0;
		vector<bool> s;
		for(int64_t i = 0; i < n; i++) {
			if(mask & (1 << i)) {
				s1 += pow(i+1, k);
				s.push_back(0);
			} else {
				s2 += pow(i+1, k);
				s.push_back(1);
			}
		}
		int64_t diff = abs(s1 - s2);
		// cout << diff << '\n';
		if(diff < sum) {
			sum = diff;
			ans.clear();
			ans.resize(n);
			ans.assign(s.begin(), s.end());
		}
	}
	cout << sum << '\n';
	for(bool i : ans)
		cout << i;
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> k;
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

