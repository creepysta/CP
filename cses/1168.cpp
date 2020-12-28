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
	string s;
	cin >> s;
	vector<ll> cnt(26, 0ll);
	for(char c : s) {
		cnt[c-'A'] ++;
	}
	ll n = s.length();
	ll odd = 0, oi = -1, even = 0;
	for(int i = 0; i < 26; i++) {
		if(cnt[i] % 2) odd++, oi = i;
		else even ++;
	}
	if(n % 2 == 0 && odd) {
		cout << "NO SOLUTION\n";
		return;
	}
	if(odd > 1) {
		cout << "NO SOLUTION\n";
		return;
	}
	string ans = "";
	for(int i = 0; i < 26; i++) {
		if(cnt[i] % 2 == 0) {
			cnt[i] /= 2;
			ans += string(cnt[i], i+'A');
		}
	}
	if(oi != -1) {
		ans += string(cnt[oi], oi+'A');
		cnt[oi] = 0;
	}
	for(int i = 25; i >= 0; i--) {
		ans += string(cnt[i], i+'A');
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

