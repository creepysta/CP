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
	vector<int> a(n);
	int big = INT_MIN, ans = INT_MIN;
	for(int i=0; i < n; i++) {
		cin >> a[i];
		big = max(big, a[i]);
	}
	vector<int> cnt(big+1, 0);
	// complexity: O(n*sqrt(a[i]) + h)
	/*
	for(int i = 0; i < n; i++) {
		for(int j = 1; j <= sqrt(a[i]); j++) {
			if(a[i] % j == 0) {
				cnt[j]++;
				if(a[i] / j != j) cnt[a[i]/j]++;
			}
		}
	}

	for(int i = big; i >= 1; i--) {
		if(cnt[i] > 1) {
			cout << i << endl;
			break;
		}
	}
	*/
	// open question don't know running time complexity
	for(int i : a)
		cnt[i] ++;
	ll counter = 0LL;
	for(int i = big; i >= 1; i--) {
		counter = 0LL;
		for(int j = i; j <= big; j+=i) {
			if(cnt[j] >= 2) {
				cout << j << endl;
				return;
			}
			else if(cnt[j] == 1)
				counter++;
			if(counter == 2) {
				cout << i << endl;
				return;
			}
		}
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
