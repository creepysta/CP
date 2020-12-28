/*
	author: Creepysta
	09-10-2020 01:19:56
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n, x, p, k;
	vector<int> a(n);
	for(int &i : a)
		cin >> i;
	sort(a.begin(), a.end());
	p--, k--;
	if(p == k) {
		if(a[p] != x)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
		return;
	}
	function<int(int)> pos = [&] (int key) {
		int low = 0, int h = p;
		int ans = -1;
		while(low <= high) {
			int mid = low + (high - low) / 2;
			if(mid >= a[p]) {
				ans = low;
				low = mid + 1;
			} else
				high = mid - 1;
		}
		return ans;
	};
	// find the position where x to be inserted and count + 1
	// if p < k and a[x] > a[p] ans = -1
	// if p > k and a[x] < a[p] ans = -1
	// loop to inc count for ans if no more elem to dec or inc then ans = -1 else ans
	if(p < k) {
		if(a[k] < a[p]) {
			if(x < a[p]) {
				}
		}
	} else {

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

