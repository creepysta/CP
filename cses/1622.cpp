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

const int mod = 1e9 + 7;

ull fact(int n) {
	ull res = 1;
	while(n > 0) {
		res *= n--;
	}
	return res;
}

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	sort(s.begin(), s.end());
	vector<int> cnt(26);
	for(char c : s)
		cnt[c - 'a'] ++;
	ull nums = fact(n);
	for(int i = 0; i < 26; i++) {
		nums /= fact(cnt[i]);
	}
	cout << nums << endl;
	string init = s;
	do {
		cout << s << endl;
	} while(next_permutation(s.begin(), s.end()));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}

