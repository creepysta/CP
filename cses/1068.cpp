#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int

int32_t main() {
	// ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ull n;
	cin >> n;
	while (n != 1) {
		if(n&1) {cout << n << ' '; n = 3ULL*n+1;} 
		else {cout << n << ' '; n/=2ULL;}
	}
	cout << 1;
	return 0;
} 