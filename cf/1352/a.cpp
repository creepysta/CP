#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		vector<ll> ans;
		ll i = 0;
		while(n > 0) {
			ll temp = n % 10;
			if(temp) {
				ans.emplace_back((ll) temp*pow(10, i));
			}
			n /= 10;
			i++;
		}
		cout << ans.size() << endl;
		for(ll ii = (ll) ans.size() -1; ii >= 0; ii --) {
			cout << ans[ii] << " ";
		}
		cout << endl;
	}
	return 0;
}
