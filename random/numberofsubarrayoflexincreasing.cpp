/*
	author: Creepysta
	26-09-2020 09:23:22
*/
#include <bits/stdc++.h>
using namespace std;

/*
 *	1 3 2 4
 *	Ans : 2
 *	(1, 3) (2) (4)
 *	(1, 3) (2, 4)
 *	prolly some dp
 *	
 */

const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int &i : a)
		cin >> i;
	int inc = 0;
	for(int i = 0; i < n; i++) {
		bool got = false;
		while(i < n-1 and a[i] < a[i+1])
			got = true, i++;
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

