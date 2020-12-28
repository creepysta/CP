#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ld long double
#define endl '\n'

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	vector<ull> cnt(26);
	for(char c : s)
		cnt[c-'A'] += 1ULL;
	int ev=0, od=0;
	for(int i = 0; i < 26; i++) {
		if(cnt[i]) {
			if(cnt[i] & 1) od++;
			else ev++;
		}
	}
	if(od > 1) {
		cout << "NO SOLUTION\n";
		return;
	}
	if(n%2 == 0 && od) {
		cout << "NO SOLUTION\n";
		return;
	}
	string ans = "", mid = "";
	for(int i = 0; i < 26; i++) {
		if(!cnt[i]) continue;
		if(cnt[i] & 1) {
			mid += string(cnt[i], 'A'+i);
			cnt[i] = 0;
		} else {
			ans+= string(cnt[i]/2, 'A'+i);
			cnt[i] /= 2;
		}
	}
	ans += mid;
	for(int i = 25; i >= 0; i--) {
		ans+= string(cnt[i], 'A'+i);
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t=1;
	//cin >> t;
	for(int tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}
