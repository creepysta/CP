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
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(ll & i : a)
		cin >> i;
	for(ll i = 1; i < n; i++) {
		a[i] += a[i-1];
	}
	ll ans = 0, j =0;
	for(ll i = 0 ; i < n; i++) {
		if(a[i] == k) {
			ans ++;
		} else if(a[i] > k) {
			ll sum = a[i];
			while(sum - a[j] > k) j++;
			sum -= a[j];
			if(sum == k)
				ans++;
		}
	}
	cout << ans << endl;
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

