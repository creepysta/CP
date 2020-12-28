//tuple

#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void operator<<(ostream &cout, const pair<int, int> &p) {
	cout << p.first << ' ' << p.second << endl;
}



void solve() {
	for(int i = 0; i < 3; i++) cin >> a[i];
	for(int i = 0; i < 3; i++) cin >> p[i];
	int a[3];
	int p[3];
	pair<int, int> diff[3];
	for(int i = 0; i < 3; i++) {
		diff[i] = {p[i]/a[i], p[i]%a[i]};
	}
	bool same = true;
	int steps = 0, numsame = 0;
	while(1) {
		for(int i = 0; i < 3; i++) {
			if(dp[i].first == 1 && dp.second == 0) {
				same = false;
			}
		}
		if(same) break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}
