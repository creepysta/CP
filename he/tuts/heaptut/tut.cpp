#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n;
	scanf("%lld", &n);
	ll a[3];
	memset(a, -1, sizeof(a));
	ll c = 0;
	while(c < n) {
		ll x; scanf("%lld", &x);
		if(c<2) puts("-1");
		int i = 0;
		while(i < n && x < a[i]) i++;
		for(int j = 2; j > i; j--) {
			a[j] = a[j-1];
		}
		a[i] = x;
		if(c >= 2) {
			printf("%lld %lld %lld\n", a[0], a[1], a[2]);
		}
		c++;
	}
}
