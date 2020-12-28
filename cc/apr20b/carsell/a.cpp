#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);


int main() {
	fastio;
	const auto MOD = 1000000007;
	ll t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		vector<ll> a(n,0);
		for(ll i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end(), [](ll i, ll j){return i > j;});
		ll profit = 0;
		for(ll i = 0; i < n; i++) {
			profit += a[i] - i < 0 ? 0 : a[i] - i;
			profit %= (ll) MOD;
		}
		cout << profit << endl;
	}
	
	return 0;
}
