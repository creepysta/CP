/*
	author: Creepysta
	13-11-2020 12:03:19
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

bool found(int n) {
	set<int> s;
	int digits = 0;
	while(n) {
		digits ++;
		s.insert(n%10);
		n/=10;
	}
	if(s.size() < digits) {
		return 0;
	}
	return 1;
}

void solve() {
	int n;
	cin >> n;
	for(int i = n+1; i < 1e6; i++) {
		if(found(i)) {
			cout << i;
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	solve();
	return 0;
}

