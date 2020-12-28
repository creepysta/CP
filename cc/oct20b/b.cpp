/*
	author: Creepysta
	18-10-2020 11:13:35
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9 + 7;

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(ll &i : a)
		cin >> i;
	for(ll i = 0; i < n; i++) {
		if(i)
			a[i] += max(0LL, a[i-1] - k);
		if(a[i] < k) {
			cout << i+1 << '\n';
			return;
		}
	}
	ll extras = a[n-1] - k;
	ll ans = n + (extras + k) / k;
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

