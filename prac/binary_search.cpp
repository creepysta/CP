/*
	author: Creepysta
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int &i : a)
		cin >> i;
	while(q--) {
		int x;
		cin >> x;
		bool found = false;
		int l = 0, h = n-1;
		// cerr << x << endl;
		while(l <= h) {
			int mid = l + (h - l) / 2;
			if(a[mid] == x) {
				cout << "YES\n";
				found = true;
				break;
			} else if(a[mid] < x)
				l = mid + 1;
			else
				h = mid - 1;
		}
		if(!found)
			cout << "NO\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

