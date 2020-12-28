/*
	author: Creepysta
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	long long n;
	cin >> n;
	vector<long long> a(n);
	for(long long &i : a)
		cin >> i;
	if(n == 1) {
		for(long long i = 0; i < 2; i++) {
			cout << 1 << ' ' << 1 << '\n';
			cout << 0 << '\n';
		}
		cout << 1 << ' ' << 1 << '\n';
		cout << -a[0] << '\n';
		return;
	}
	cout << 1 << ' ' << 1 << '\n' << -a[0] << '\n';
	cout << 1 << ' ' << n << '\n';
	for(long long i = 1; i <= n; i++) {
		if(i == 1)
			cout << 0 << ' ';
		else
			cout << n * (-a[i-1]) << ' ';
	}
	cout << '\n';
	cout << 2 << ' ' << n << '\n';
	for(long long i = 2; i <= n; i++) {
		cout << (n-1) * (a[i-1]) << ' ';
	}
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

