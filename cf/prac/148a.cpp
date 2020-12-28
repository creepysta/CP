/*
	author: Creepysta
	13-11-2020 12:15:18
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	vector<int> a(4);
	int d;
	for(int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cin >> d;
	vector<bool> damaged(d+1, 0);
	int ans = 0;
	for(int i : a) {
		if(!damaged[i]) {
			for(int j = i; j <= d; j += i) {
				damaged[j] = true;
			}
		}
	}
	for(bool b : damaged) {
		if(b) {
			ans ++;
		}
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	solve();
	return 0;
}

