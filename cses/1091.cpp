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
	int n, m, ticket, cus;
	cin >> n >> m;
	multiset<int, greater<int>> tickets;
	vector<int> a(m);
	for(int i = 0; i < n; i++) {
		cin >> ticket;
		tickets.insert(ticket);
	}
	for(int i = 0; i < m; i++) {
		cin >> cus;
		auto it = tickets.lower_bound(cus);
		if(it == tickets.end()) {
			cout << -1 << endl;
			continue;
		}
		cout << *it << endl;
		tickets.erase(it);
	}
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

