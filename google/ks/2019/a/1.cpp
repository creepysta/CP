#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t;
	cin >> t;
	ll tests = 1;
	while(tests <= t) {
		ll n, p;
		cin >> n >> p;
		vector<ll> a(n);
		for(ll &i : a) {
			cin >> i;
		}
		sort(a.begin(), a.end());
		ll initSum = 0, ans = LLONG_MAX;
		for(ll i = 0; i < p; i++) {
			initSum += a[p-1] - a[i];
		}
		for(ll i = 1; i < n; i++) {
			initSum += a[n-p -1] - a[i-1];
			ans = min(initSum, ans);
		}
		cout << "Case #" << tests << ": " << ans << endl;
		tests++;
	}
	return 0;
}
