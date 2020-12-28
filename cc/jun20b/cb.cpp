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
	ll n;
	cin >> n;
	multiset<ll> changes;
	bool ok = true;
	for(ll i = 0 ;i < n; i++) {
		int x;
		cin >> x;
		if(x==5) {
			changes.insert(x);
		}
		else if(x == 10) {
			if(changes.find(5) != changes.end()) {
				changes.erase(changes.find(5));
				changes.insert(10);
			} else ok = false;
		}
		else if(x==15) {
			if(changes.count(5) > 1) {
				changes.erase(changes.find(5));
				changes.erase(changes.find(5));
			} else if(changes.count(10) > 0) {
				changes.erase(changes.find(10));
			} else ok = false;
		}
	}
	if(ok) cout << "YES\n";
	else cout << "NO\n";
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
