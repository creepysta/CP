#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int

int32_t main() {
	ull n;
	cin >> n;
	ull zeros = 0ULL;
	for(ull f = 5; n / f >= 1; f*=5) {
		zeros += n/f;
	}
	cout << zeros;
	return 0;
}
