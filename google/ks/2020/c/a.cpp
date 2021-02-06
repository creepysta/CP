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
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int start = 0, diff = a[1] - a[0], ans = 2;
	int i = 2;
	for(; i < n ; i++) {
		if(a[i] - a[i-1] != diff) {
			start = i-1;
			diff = a[i] - a[i-1];
		}
		ans = max(ans, i - start + 1);
	}
	cout << ans << endl;
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

