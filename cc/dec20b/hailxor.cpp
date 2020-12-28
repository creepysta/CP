/*
	author: Creepysta
	09-12-2020 09:53:25
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e9) + 7;

/*
2 2 3
10
10
11


2 3 2 4	| 2 3 2 4
0 3 0 4	| 0 1 2 4
0 1 0 6	| 0 0 3 4
0 0 0 7 | 0 0 1 6


 10
 11
 10
100

43 > 7 > 
100 
 11 

34 > 70x
34 > 16 > 7
 11
100
*/

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for(int &i : a)
		cin >> i;
	set<int> table[32];
	vector<int> one(n), two(n);
	for(int i = 0; i < n; i++) {
		for(int mask = 0; mask < 31; mask++) {
			if(a[i] & (1 << mask))
				table[mask].insert(i);
		}
	}
	// start at 0
	// if a[i] > 0
	// find other a[j] > 0 where j > i
	// make a[i] = 0 and --x
	for(int i = 0; i < n; i++) {
		int msbbit = 32 - __builtin_clz(a[i]);
		int l = -1, m = -1;
		if(msbbit != 0) {
			l = i;
		}
		if(table[index].size() == 1) {
			if(i < n-1)
				m = a[i+1];
		}
		while(x && a[i]) {
			for(int ei : table[index]) {
				if(l == -1)
					l = ei;
				else if(m == -1)
					m = ei;
				else
					break;
			}
			table[msbbit].remove(l);
			table[msbbit].remove(m);
			int li = 32 - __builtin_clz(a[l] ^ (1 << (msbbit - 1)));
			table[li].insert(i);
			int ei = 32 - __builtin_clz(a[m] ^ (1 << (msbbit - 1)));
			table[ei].insert(i);
			x--;
		}
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

