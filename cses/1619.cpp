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
	int n;
	cin >> n;
	vector<pair<int, bool>> a;
	for(int i = 0; i < n; i++) {
		int in, out;
		cin >> in >> out;
		a.push_back({in, true});
		a.push_back({out, false});
	}
	sort(a.begin(), a.end());
	int curr = 0, people = 0;
	for(int i = 0; i < (int) a.size(); i++) {
		curr += a[i].ss ? 1 : -1;
		people = max(people, curr);
	}
	cout << people << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll t=1;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}

