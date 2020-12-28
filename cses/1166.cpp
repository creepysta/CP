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
	int n;
	cin >> n;
	if(n == 1) {
		cout << 1 << endl;
		return;
	}
	if (n <= 3) {
		cout << "NO SOLUTION\n";
		return;
	}
	for(int i = n-1; i >= 1; i-=2) {
		cout << i << ' ';
	}
	for(int i = n; i >= 1; i-=2) {
		cout << i << ' ';
	}
	cout << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll t=1;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}

