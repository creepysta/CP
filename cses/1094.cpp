#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int

int32_t main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ull ans = 0ull;
	for(int i = 1; i < n; i++) {
		if(a[i] < a[i-1]) ans += a[i-1] - a[i], a[i] = a[i-1];
	}
	cout << ans;
	return 0;
}
