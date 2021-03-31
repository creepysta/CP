/*
	author: Creepysta
	03-03-2021 12:41:20
*/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int MOD = int(1e9) + 7;
const int lim = LLONG_MIN;

struct seg {
	vector<int> a;
	int n;
	seg(const vector<int> &v) {
		n = 1;
		while(n < (int) v.size())
			n <<= 1;
		a.resize(2*n, lim);
		build(v, 0, 1, n-1);
	}
	inline void pull(int x) { a[x] = min(a[2*x], a[2*x+1]); }
	void build(const vector<int> &v, int x, int lx, int rx) {
		if(rx == lx) {
			if(lx < (int) v.size()) {
				a[x] = v[lx];
			}
			return;
		}
		int mid = lx + (rx - lx)/ 2;
		build(v, 2*x, lx, mid);
		build(v, 2*x + 1, mid + 1, rx);
		pull(x);
	}
	int query(int l, int r, int x, int lx, int rx) {
		if(l > r) return lim;
		if(lx > r || rx < l) return lim;
		if(l <= lx && r >= rx) return a[x];
		int mid = lx + (rx - lx) / 2;
		int lt = query(l, r, 2*x, lx, mid);
		int rt = query(l, r, 2*x + 1, mid + 1, rx);
		return min(lt, rt);
	}
	int query(int l, int r) {
		return query(l, r, 1, 0, n-1);
	}
};

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	seg s(a);
	int low = 0, high = d
}

signed main() {
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

