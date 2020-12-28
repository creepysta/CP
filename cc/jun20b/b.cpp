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
	string a;
	cin >> a;
	ll n = a.size();
	ll ans = 0;
	for(ll i = 0; i<n;i++) {
		if(a[i] == 'x' && a[i+1] == 'y') {
			ans += 1;
			i++;
		}
		else if(a[i] == 'y' && a[i+1] == 'x') {
			ans +=1;
			i++;
		}
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}
