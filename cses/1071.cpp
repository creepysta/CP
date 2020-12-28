#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int

void solve() {
	ull x, y;
	cin >> x >> y;
	ull sqr = (ull) max(x, y);
	ull low = (sqr-1) * (sqr-1) + 1, high = sqr*sqr;
	if(sqr & 1) {
		if(x <= y) {
			high -= x-1;
			cout << high;
		} else {
			low += y-1;
			cout << low;
		}
	} else {
		if(x <= y) {
			low += x-1;
			cout << low;
		} else {
			high -= y-1;
			cout << high;
		}
	}
	cout << endl;
	return;
}

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
