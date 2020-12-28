#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

int findsum(int n) {
	int sum = 0;
	while(n) {
		sum += n%10;
		n/=10;
	}
	return sum;
}

void solve() {
	int n;
	cin >> n;
	int a = 0, b = 0;
	for(int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		if(findsum(x) > findsum(y)) a+=1;
		else if(findsum (x) < findsum(y)) b += 1;
		else a++, b++;
	}
	if(a == b) cout << 2 << ' ' << a << endl;
	else cout << (a > b ? 0 : 1) << ' ' << (a > b ? a : b) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}
