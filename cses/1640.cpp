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

const int MAX = 1e9+1;

void solve() {
	ll n, x;
	cin >> n >> x;
	assert(x < MAX); 
	vector<pair<ll, ll>> a(n);
	unordered_map<ll, ll> tab;
	bool got = false;
	for(ll i = 0; i < n; i++) {
		ll k;
		cin >> k;
		assert(k < MAX);
		a[i].ff = k;
		a[i].ss = i+1;
		// auto it = tab.find(k);
		// if(it == tab.end()) tab[x-k] = i+1;
		// else {
		//	cout << i+1 << ' ' << it->second << endl;
		//	got = true;
		//	break;
		// }
	}
	ll i = 0, j = n-1;
	sort(a.begin(), a.end());
	while(i < j) {
		if(a[i].ff + a[j].ff == x) {
			cout << a[i].ss << ' ' << a[j].ss << endl;
			got = true;
			break;
		}
		else if(a[i].ff + a[j].ff < x)
			i++;
		else
			j--;
	}
	if(!got)
		cout << "IMPOSSIBLE\n";
	return;
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

