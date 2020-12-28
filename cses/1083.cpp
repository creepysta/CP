#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	int n;
	cin >> n;
	int x=1, ans=1;
	for(int i = 0; i < n-1; i++) {
		int cc; cin >> cc;
		x ^= cc;
	}
	for(int i = 1; i <= n; i++) {
		ans ^= i;
	}
	ans = ans^x;
	cout << ans;
	return 0;
}
