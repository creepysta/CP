#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve() {
	int n;
	cin >> n;
	char cc[n];
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		cin >> cc[i];
		if(cc[i] == 'A') cnt ++;
		else cnt --;
	}
	if(abs(cnt-0) == 1) cout << 'Y';
	else cout << 'N';
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		cout << "Case #" << tt << ": ";
		solve();
	}

	return 0;
}
