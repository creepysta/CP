#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define MOD 1000000007
#define endl '\n'

void solve() {
	int n;
	cin >> n;
	int layers = ceil(n/2.0);
	int a[n][n];
	int val = 1;
	for(int i = 0; i < layers; i++) {
		// top
		for(int j = i; j < n-i-1; j++) {
			a[i][j] = val ++;
		}
		// right
		for(int j = i; j < n-i-1; j++) {
			a[j][n-i-1] = val++;
		}
		// bottom
		for(int j = n-i-1; j > i; j--) {
			a[n-i-1][j] = val++;
		}
		// left
		for(int j = n-i-1; j > i; j--) {
			a[j][i] = val ++;
		}
	}
	if(n%2)
	a[(int)n/2][(int)n/2] = n*n;
	for(int i = 0; i < n; i++, cout << endl) for(int j = 0; j < n; j++) cout << a[i][j] << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}

