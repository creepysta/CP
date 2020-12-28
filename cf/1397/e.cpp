/*
	author: Creepysta
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

void solve() {
	ll n, r1, r2, r3, d;
	cin >> n >> r1 >> r2 >> r3 >> d;
	vector<ll> a(n);
	for(ll &i : a)
		cin >> i;
	vector<pair<ll, ll>> choice(n+3);
	ll kill = a[i] * r1 + r3,
	   run = min((a[i] + 1) * r1, r2);
	choice[0] = make_pair(kill, run);
	for(int i = 1; i < n; i++) {
		choice[i] = 
	}
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

