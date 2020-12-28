#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define ff first
#define ss second
#define endl '\n'

const ll MOD = 1e9 + 7;

void solve() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int i = 0, big = n, small = 1;
	vector<int> aa(n, small);
	for(i = n-1; i >= n-(b-c); i--) {
		aa[i] = ceil(big/2.);
	}
	for(i = 0; i < a-c; i++) {
		aa[i] = ceil(big/2.);
	}
	for(i = min(a-c, b-c); i < c; i++) {
		aa[i] = big;
	}
	for(int v : aa)
		cout<< v << ' ';
	cout << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		cout << "case #" << tt << ": ";
		solve();
	}

	return 0;
}

