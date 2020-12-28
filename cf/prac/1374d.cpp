#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t; cin >> t;
	//t = 1;
	while(t--) {
		ll n, k;
		cin >> n >> k;
		ll a[n];
		ll x = 0;
		ll steps = 0;
		bool div = true;
		for(ll i = 0; i < n; i++) {
			cin >> a[i];
			if(a[i] %k) div = false;
		}
		for(int i : a) cout << i << ' ';
		cout << endl;
		if(div) {cout<< 0 << endl;continue;}
		sort(a, a+n, greater<int>());
		for(ll i = 0; i < n; i++) {
			if(a[i]%k) {
				ll q = (ll) ceil((a[i]+x)/(double)k);
				ll diff = k*q - a[i];
				steps += diff -x;
				x += diff;
				x++;
				steps++;
			} else {
				if(x and (a[i]+x) %k == 0) steps ++, x++;
			}
		}
		cout << steps << endl;
	}
	return 0;
}
