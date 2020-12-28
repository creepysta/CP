#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int

const int mod = 1e9+7;

ull power(ull a, ull b) {
	ull result = 1;
	while(b) {
		if(b&1) result = (result * a) % mod;
		a = ((a %mod)* (a % mod)) % mod;
		b >>= 1;
	}
	return result;
}

int32_t main() {
	int n; cin >> n;
	ull ans = power(2, n) % mod;
	cout << ans << endl;
	return 0;
}
