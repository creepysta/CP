/*
	author: Creepysta
	04-09-2020 13:02:35
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int64_t inf = 1e17;

inline int64_t pow(int64_t a, int64_t b) {
	return (inf / a > b ? a * b : inf);
}

inline int64_t add(int64_t a, int64_t b) {
	return (a + b >= inf ? inf : a + b);
}

void solve() {
	int64_t n;
	cin >> n;
	vector<int64_t> a(n);
	for(int64_t &i : a)
		cin >> i;
	sort(a.begin(), a.end());
	if(n <= 2) {
		cout << a[0] - 1 << '\n';
		return;
	}
	int64_t ans = accumulate(a.begin(), a.end(), 0ll) - n;
	for(int64_t x = 1; ; ++x) {
		int64_t curPow = 1, curCost = 0;
		for(int64_t i = 0; i < n; i++) {
			curCost = add(curCost, abs(a[i] - curPow));
			curPow = pow(curPow, x);
		}
		if(curPow == inf || curPow / x > ans + a[n-1])
			break;
		ans = min(ans, curCost);
	}
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
