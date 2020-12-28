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

void solve() {
	int n, x;
	cin >> n >> x;
	vector<pair<int, int>> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i].ff;
		a[i].ss = i+1;
	}
	sort(a.begin(), a.end());
	set<pair<int,int>> tab;
	for(int i = 0; i < n; i++) {
		int low = i+1, high = n-1;
		int tofind = x - a[i].ff;
		int idx = a[i].ss;
		while(low < high) {
			ll sum = a[low].ff + a[high].ff;
			if(sum == tofind) {
				cout << idx << ' ' << a[low].ss << ' ' << a[high].ss << endl;
				return;
			} else if(sum < tofind)
				low++;
			else high --;
		}
	}
	cout << "IMPOSSIBLE\n";
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll t=1;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}

