/*
	author: Creepysta
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

pair<int, int> count(long long num) {
	int idx;
	for(int i = 61; i >= 0; i--) {
		if((num & (1ll << (long long) i))) {
			idx = i;
		}
	}
	int id, ans = 0;
	for(int i = idx; i >= 0; i--) {
		if((num & (1ll << (long long) i)) == 0) {
			ans++;
			id = i;
		}
	}
	int ones = 0;
	for(int i = id - 1; i >= 0; i--) {
		if((num & (1ll << (long long) i))) {
			ones ++;
		}
	}
	if(ans == 1)
		return make_pair(ones, id);
	return make_pair(0, -1);
}

void solve() {
	long long l, r, temp, ans = 0;
	cin >> l >> r;
	temp = l;
	for(int i = 0; i < 60; i++) {
		ans += count(temp).first;
		if(temp > r)
			continue;
		
		temp |= 1ll << (long long) i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

