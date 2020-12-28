#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

ll Func = 0;
ll leastZ = 0;

ll solve(ll x, ll y, ll z, ll r, ll check) {
	ll F = (x&z) * (y&z);
	if((z|check) > r) {
		if(F > Func) {
			Func = F;
			leastZ = z;
		}
		return F;
	}
	if((x & check) || (y & check)) {
		return max(solve(x, y, z|check, r, check << 1), solve(x, y, z, r, check << 1));
	} else {
		if((check & z)) {
			return solve(x, y, z&(!check), r, check << 1);
		} else {
			return solve(x, y, z, r, check << 1);
		}
	}
}

/* 100101
 *  10010
 *    101
 * r = 100101
*/

int main(int argc, char *argv[]) {
	//cout << argv[0] << endl;
	ll t;
	cin >> t;
	while(t--) {
		Func = 0;
		leastZ = 0;
		ll x, y, l, r;
		cin >> x >> y >> l >> r;
		if(!(x && y)) {
			cout << l << endl;
			continue;
		}
		ll ans = x|y;
		if(ans <= r) {
			if(ans < l) {
				ans = ans|l;
			}
			cout << ans << endl;
		}
		else {
			solve(x, y, l, r, 1);
			if(leastZ < l)
				leastZ |= l;
			cout << leastZ << endl;
		}
	}
	
	return 0;
}
