#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define ff first
#define ss second
#define endl '\n'

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i].ff >> a[i].ss;
	}
	sort(a.begin(), a.end(), 
			[&](const pair<int, int> p, const pair<int, int> q) {
				// return (p.ss - p.ff) > (q.ss - q.ff);
				return p.ff < q.ff;
			}
		);
	ll ans = 0, red = 0;
	for(int i = 0; i < n; i++) {
		ans += a[i].ss - a[i].ff;
		if(i) {
			red += a[i-1].ff;
			ans -= red;
		}
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll t=1;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}

