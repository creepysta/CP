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
	vector<tuple<int, int, bool>> a(n);
	for(int i = 0; i < n; i++) {
		/*int x, y;
		cin >> x >> y;
		a[i] = make_tuple(x, y, true);*/
		cin >> get<0>(a[i]) >> get<1>(a[i]);
		get<2>(a[i]) = true;
	}
	for(int i = 1; i < n; i++) {
		// ll check = get<0>(a[i]) + get<0>(a[(i+1)%n]) - get<1>(a[i]);
		if(get<1>(a[i]) > get<0>(a[(i+1)%n])) {
			get<2>(a[i]) = false;
		}
	}
	int ans = 0;
	for(auto tt : a) {
		if(!get<2>(tt))
			ans ++;
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
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}

