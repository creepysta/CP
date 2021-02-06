#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t;
	cin >> t;
	while(t--) {
		ll n, m, q;
		ll ans = 0;
		cin >> n >> m >> q;
		vector<bool> pg(n+1, 1);
		while(m--) {
			int tp;
			cin >> tp;
			pg[tp] = 0;
		}
		while(q--) {
			int r;
			cin >> r;
			for(ll j = r; j <= n; j+= r) {
				if(pg[j]) {
					ans ++;
					//cout << ans << " ";
					//pg[j] = 0;
				}
			}
			//cout << endl;
		}
		cout << ans << endl;
	}
	
	return 0;
}
