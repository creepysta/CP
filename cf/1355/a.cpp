#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

ll find(ll n) {
	ll mi=9, ma = 0;
	while(n) {
		ll unit = n % 10;
		mi = min(mi, unit);
		ma = max(ma, unit);
		n /= 10;
	}
	return mi *ma;
}

int main() {
	fastio;
	ll t;
	cin >> t;
	while(t--) {
		ll n, k;
		cin >> n >> k;
		ll a1 = n, a2 = a1;
		for(ll i = 1; i < k;i++) {
			ll add = find(a1);
			if(!add) break;
			a2 = a1 + add;
			a1 = a2;
		}
		cout << a1 << endl;
	}
	
	return 0;
}
