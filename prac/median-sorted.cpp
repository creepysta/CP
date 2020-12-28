#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define MOD 1000000007
#define endl '\n'

ld solve(const vector<ll> &a, const vector<ll> &b) {
	ll n = a.size(), m = b.size();
	if(n > m) return solve(b, a);
	ll low = 0, high = n;
	ll bpart = (n+m+1) /2;
	while(low <= high) {
		ll xpart = low + (high - low)/2;
		ll ypart = bpart - xpart;
		ll xmin = xpart ? a[xpart-1] : MIN, xmax = xpart < n ? a[xpart] : MAX;
		ll ymin = ypart ? b[ypart-1] : MIN, ymax = ypart < m ? b[ypart] : MAX;
		//cout << xmin << ' ' << ymin << ' ' << xmax << ' ' << ymax << endl;
		if(xmin <= ymax && ymin <= xmax) {
			ld ans = 0.0;
			if((n+m)%2)
				ans = (ld) max(xmin, ymin)*1.0;
			else
				ans = (max(xmin, ymin), min(xmax, ymax))/2.0;
			//cout << ans << endl;
			//break;
			return ans;
		}
		if(xmin > ymax)
			high = xpart -1;
		else
			low = xpart + 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		cout << "case #" << tt << ":\n";
		int n, m;
		cin >> n >> m;
		vector<ll> a, b;
		a.clear(); a.resize(n);
		b.clear(); b.resize(m);
		for(ll & i: a) cin >> i;
		for(ll &i :b) cin>> i;
		ld ans = solve(a, b);
		cout << ans << endl;
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
