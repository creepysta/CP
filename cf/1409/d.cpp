/*
	author: Creepysta
	05-09-2020 08:00:42
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

ll sum(ll n) {
	ll sum = 0;
	while(n) {
		sum += n%10;
		n /= 10;
	}
	return sum;
}


void solve() {
	ll n, s;
	cin >> n >> s;
	if(sum(n) <= s) {
		cout << 0 << '\n';
		return;
	}
	ll p = 1, ans = 0;
	for(int i = 0; i < 18; i++) {
		int digit = (n / p) % 10;
		ll add = p * (10 - digit);
		n += add;
		ans += add;
		if(sum(n) <= s)
			break;
		p *= 10;
	}
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

