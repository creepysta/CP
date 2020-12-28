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
	vector<int> tab(n);
	// unordered_set<int> tab;
	int dis = 1;
	for(int i = 0; i < n; i++) {
		// int x; cin >> x;
		// tab.insert(x);
		cin >> tab[i];
	}
	// dis = tab.size();
	sort(tab.begin(), tab.end());
	for(int i = 1; i < n; i++) {
		if(tab[i] != tab[i-1]) dis++;
	}
	cout << dis << endl;
	return;
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

