#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
// 0 1
// y n
// y y

void solve() {
	int n;
	cin >> n;
	char ii[n], oo[n];
	for(char &c : ii) cin >> c;
	for(char &c : oo) cin >> c;
	char ans[n][n];
	memset(ans, 'N', sizeof(ans));
	for(int i = 0; i < n; i++) {
		ans[i][i] = 'Y';
		for(int k = i-1; k >= 0; k--) {
			if(oo[k+1] == 'Y' && ii[k] == 'Y') ans[i][k] = 'Y';
			else break;
		}
		for(int k = i+1; k < n; k++) {
			if(oo[k-1] == 'Y' && ii[k] == 'Y') ans[i][k] = 'Y';
			else break;
		}
	}
	for(int i=0; i < n; i++, cout << endl)
		for(int j = 0; j < n; j++)  cout << ans[i][j];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		cout << "Case #" << tt << ":\n";
		solve();
	}

	return 0;
}
