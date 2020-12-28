/*
	author: Creepysta
	05-09-2020 20:56:05
*/
#include <bits/stdc++.h>
using namespace std;
/*
 *  1  2  3  4
 *  5  6  7  8
 *  9 10 11 12
 * 13 14 15 16
 * */
const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	int a[n][n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int problem = 0, fixed = 0, turn = 0;
	bool pcheck = false, fcheck = false;
	vector<int> row(n);
	row[0] = 1;
	for(int i = 1; i < n; i++)
		if(a[0][i] == i+1)
			row[i] = 0;
		else
			row[i] = 1;
	for(int i = n-1; i > 0; i--) {
		while(i > 0 && row[i] == 1) {
			pcheck = true;
			i--;
		}
		if(pcheck) {
			turn++;
			while(i > 0 && row[i] == 0) {
				fcheck = true;
				i--;
			}
			if(fcheck)
				turn++, i++;
		}
		pcheck = fcheck = false;
	}
	for(int i : row)
		cout << i << ' ';
	cout << '\n';
	cout << turn << '\n';
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

