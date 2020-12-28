#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define ff first
#define ss second

void operator<<(ostream &cout, const pair<int, int> &a) {
	cout << a.ff << ' ' << a.ss << endl;
}

void solve() {
	int n;
	cin >> n;
	n = 4*n -1;
	int x = 0, y= 0;
	for(int i = 0; i <n ; i++) {
		int a, b;
		cin >> a >> b;
		x ^=a;
		y ^=b;
	}
	cout << x << ' ' << y << endl;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		solve();
	}

	return 0;
}
