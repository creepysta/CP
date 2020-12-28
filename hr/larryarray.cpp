/*
	author: Creepysta
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

/*
	1 2 3	3 1 2	2 3 1	1 2 3
	2 1 3
*/
int merge(vector<int> &a, int l, int mid, int r) {
	int inv = 0;
	vector<int> b(a.size());
	int i = l,
		j = mid,
		k = l;
	while(i < mid && j <= r) {
		if(a[i] <= a[j])
			b[k++] = a[i++];
		else {
			b[k++] = a[j++];
			inv += mid - i;
		}
	}
	while(i < mid)
		b[k++] = a[i++];
	while(j <= r)
		b[k++] = a[j++];
	for(int idx = l; idx <= r; idx++)
		a[idx] = b[idx];
	return inv;
}

int inversions(vector<int> &a, int l, int r) {
	int inv = 0;
	if(l < r) {
		int m = l + (r - l) / 2;
		inv += inversions(a, l, m);
		inv += inversions(a, m+1, r);
		inv += merge(a, l, m+1, r);
	}
	return inv;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int &i : a)
		cin >> i;
	/*
	   int inv = 0;
	   for(int i = 0; i < n; i++) 
	   for(int j = i+1; j < n; j++) 
	   if(a[i] > a[j])
	   inv ++;
	 */
	int minv = inversions(a, 0, n-1);
	// cout << inv << ' ' << minv << '\n';
	if(minv % 2 == 0)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

