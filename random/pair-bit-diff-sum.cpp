/*
	author: Creepysta
	10-03-2021 08:54:44
*/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int MOD = int(1e9) + 7;
int n;
vector<int> a;

int brute() {
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			ans = (ans + __builtin_popcount(a[i]^a[j])) % MOD;
		}
	}
	return ans;
}

//int modpow(int x, int y) {
//	int result = 1;
//	while(y) {
//		if(y & 1) result = (result * x) % MOD;
//		x = (x*x) % MOD;
//		y >>= 1;
//	}
//	return result;
//}

int solve() {
	vector<bitset<40>> t(n);
	for(int i = 0; i < n; i++) {
		t[i] = a[i];
#ifdef LOCAL
		cerr << t[i] << endl;
#endif
	}
	int ans = 0;
	for(int i = 0; i < 40; i++) {
		int one = 0, zero = 0;
		for(int  j = 0; j < n; j++) {
			one += t[j][i];
			zero += t[j][i] == 0;
		}
		ans = (ans + (one * zero * 2) % MOD ) %MOD;
//		if(one) {
//			ans = (ans + (modpow(2,one) * zero)%MOD) %MOD;
//		}
	}
	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#ifndef LOCAL
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		cin >> n;
		a.resize(n);
		for(int i = 0; i < n; i++)
			cin >> a[i];
		int a2 = solve();
		cout << a2 << "\n";
	}
#endif
#ifdef LOCAL
	int test = 1;
	while(1) {
		mt19937 rng(test);
		cerr << test << ":\n";
		int N = 10, AN = int(1e9) + 1;
		n = rng() % N;
		a.resize(n);
		cerr << "n: " << n << endl;
		cerr << "array: " << endl;
		for(int i = 0; i < n; i++) {
			a[i] = rng()%AN;
			cerr << a[i] << ' ';
		}
		cerr << endl;
		int a1 = brute();
		int a2 = solve();
		cerr << "ans: ";
		cerr << a1 << " " << a2 << "\n";
		assert(a1 == a2);
		test ++;
	}
#endif
	return 0;
}

