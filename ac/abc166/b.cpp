#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define ff first
#define ss second
#define endl '\n'

const ll MOD = 1e9 + 7;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> tab(101);
	for(int i = 0; i < k; i++) {
		int ki;
		cin >> ki;
		while(ki --) {
			int x;
			cin >> x;
			tab[x] ++;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(! tab[i])
			ans++;
	}
	cout << ans << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll t=1;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}

