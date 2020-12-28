#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

		ll t;
		cin >> t;
		while(t--) {
				ll n, i;
				cin >> n;
				n *= 2;
				string s;
				cin >> s;
				vector<bool> ar(n);
				for(ll i = 0; i < n; i++) {
						ar[i] = s.at(i) - 48;
				}
				ll a=0, b=0;
				for(i = 0; i < n; i++) {
						if(i%2) {
								if(ar[i])
										b += 1;
						}
						else {
								if(ar[i])
										a += 1;
						}
						if(abs(a-b) > n - i) {
								if(i%2) {
										cout << i+1 << endl;
										break;
								}
						}
				}
				if(i>=n) {
						cout << i << endl;
				}
		}
		return 0;
}
