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
	/*
	   int x, n;
	   cin >> x >> n;
	   vector<int> a(n);
	   for(int i = 0; i < n; i++) {
	   cin >> a[i];
	   }
	   vector<bool> pos(x, false);
	   pos[0] = true;
	   pos[x-1] = true;
	   auto bs = [&] (int key) {
	   while(l < h) {
	   int mid = l + (h-l) / 2;
	   if(
	   };
	   for(int i = 0; i < n; i++) {

	   cout << max(abs(left-a[i]), abs(right-a[i])) << ' ';
	 */
	int x, n;
	set <int> s;
	multiset <int> m;
	cin >> x >> n;
	s.insert(0);
	s.insert(x);
	for(int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		auto l = s.lower_bound(k), r = --s.upper_bound(k);
		if(*l > k) --l;
		if(*r < k) ++r;
		auto f = m.find(*r - *l);
		if(f != m.end()) m.erase(f);
		m.insert(k - *l);
		m.insert(*r - k);
		s.insert(k);
		cout << *--m.end() << ' ';
	}
	cout << endl;
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

