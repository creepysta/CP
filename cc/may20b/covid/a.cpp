#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(ll &i : a) {
		cin >> i;
	}
	ll count = 1;
	ll min_elem = LLONG_MAX, max_elem = LLONG_MIN;
	a.push_back(15);
	// 1 2 5 6 7
	for(ll i = 1; i <= n; i++) {
		if(a[i] - a[i-1] > 2) {
			max_elem = max(count, max_elem);
			min_elem = min(count, min_elem);
			count = 1;
			continue;
		}
		count ++;
	}
	if(count == n) {
		cout << "count = n" << endl;
		max_elem = min_elem = count;
	}
	cout << min_elem << " " << max_elem << endl;
}

int main() {
	ll t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
