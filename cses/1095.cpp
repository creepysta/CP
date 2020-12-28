#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

const ll MOD = 1e9+7;

ll pwr(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b & 1) ans = (ans%MOD * a%MOD) % MOD;
		a = (a%MOD * a%MOD) % MOD;
		b >>= 1;
	}
	return ans;
}

void solve() {
	int a, b;
	cin >> a >> b;
	cout << pwr(a, b) << endl;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll t;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}


/*


ll stb(string s, ll m) {
	ll ans = 0;
	ll i = m;
	while(i--) {
		cout << s[i] << endl;
		//ans |= (s[i] - '0') << i;
	}
	cout << endl;
	//ans >>= 1;
	return ans;
}

void tobin(ll num, ll bits) {
	while(bits--) {
		cout << ((num>>bits) & 1ll);
	}
	cout << endl;
}
*/

