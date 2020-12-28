#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define ld long double
#define endl '\n'

const ll MOD = 1e9+7;

ll pwr(ll a, ll b, ll mod) {
	ll ans = 1LL;
	while(b) {
		if(b & 1LL) ans = (ans * a%mod) % mod;
		a = (a%mod * a%mod) % mod;
		b >>= 1LL;
	}
	return ans;
}

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	ll temp = pwr(b, c, MOD - 1);
	cout << pwr(a, temp, MOD) << endl;
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

