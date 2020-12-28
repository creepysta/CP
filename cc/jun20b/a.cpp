#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define MOD 1000000007
#define endl '\n'

void solve() {
	ll sum = 0;
	ll n, k;
	cin >> n >> k;
	for(ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if(x > k) {
			sum += (x-k);
		}
	}
	cout << sum << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}
