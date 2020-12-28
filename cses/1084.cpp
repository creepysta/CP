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
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> people(n), apartment(m);
	for(int i = 0; i < n; i++) {
		cin >> people[i];
	}
	for(int i = 0; i < m; i++) {
		cin >> apartment[i];
	}
	sort(people.begin(), people.end());
	sort(apartment.begin(), apartment.end());
	auto close = [&] (int a, int p) {
		return a >= (p - k) && a <= (p+k);
	};
	auto less = [&] (int a, int p) {
		return a < (p - k);
	};
	auto big = [&] (int a, int p) {
		return a > (p+k);
	};
	int ans = 0;
	for(int i = 0, j = 0; i < n; i++) {
		while(j < m && less(apartment[j], people[i])) j++;
		if(close(apartment[j], people[i])) {
			ans ++;
			j++;
		}
	}
	cout << ans << endl;
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

