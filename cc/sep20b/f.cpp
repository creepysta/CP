/*
	author: Creepysta
	18-09-2020 15:48:22
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int nax = 1e9 + 1;

int pow (int n, int a) {
	int64_t ans = 1;
	while(n) {
		if(n & 1) ans = (ans * a) % MOD;
		a = (a * a) % MOD;
		n >>= 1;
	}
	return (int) ans;
}

int mul(int a, int b) {
	return (a * b) % MOD;
}

int add(int a, int b) {
	if ((long long)a + b >= MOD)
		return (long long) a + b - MOD;
	return a+b;
}

int sub(int a, int b) {
	if(a - b < 0)
		return a - b + MOD;
	return a - b;
}

void solve() {
	int n;
	cin >> n;
	int maxcard = 0;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		maxcard = max(maxcard, a[i]);
	}
	int X = 0;
	for(int i : a)
		if(i == maxcard)
			X++;
	int remcards = n - X;
	int ans = pow(2, X);
	if(X % 2 == 0)
		ans = sub(ans, mul(X, X - 1));
	ans += mul(ans, pow(2, remcards));
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

