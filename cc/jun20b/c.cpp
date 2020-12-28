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

void solve() {
	ll n;
	cin >> n;
	ll a = 0, b = 0, c = 0;
	bool ok = true;
	//cout << n << endl;
	for(ll i = 0; i < n; i++) {
		ll x;
		cin >>x;
		if(x == 10) {
			if(a > 0) {
				a -=1;
				b += 1;
			}
			else ok = false;
		}
		else if(x == 15) {
			if( a > 1) {
				a -= 2;
				c++;
			}
			else if(b > 0) {
				b-= 1;
				c++;
			}
			else ok = false;
		}
		else {
			a ++;
		}
		//cout << a << ' ' << b << ' ' << c << ' ' << ok << endl;
		//if(!ok) break;
	}
	if(ok) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}
