#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

int main() {
	ll t;
	cin >> t;
	while(t--) {
		ll x, k;
		cin >> x >> k;
		ll factors = 0;
		while(!(x&1)) {
			x >>= 1;
			factors++;
		}
		for(ll i = 3; i*i <= x; i+=2) {
			while(x%i==0) {
				factors++;
				x /= i;
			}
		}
		if(x > 1) factors++;
		cout << (factors>=k) << endl;
	}

	return 0;
}

// 2 * 3 = 6
// num = 6
// x = {1,2,3,6} = 4
// k = 2
