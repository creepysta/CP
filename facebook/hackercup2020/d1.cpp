#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

const int inf = 1e9 + 5;

//struct BIT {
	//size_t size;
	//vector<int> tree;

//}

struct segtree {
	int size;
	vector<int> vec;
	void init(int n) {
		size = 1;
		while(size < n) size <<= 1;
		vec.assign(2*size-1, inf);
	}

	void build(const vector<int> &a, int x, int lx, int rx) {
		if(rx - lx == 1) {
			if(lx < (int) a.size()) {
				vec[x] = a[lx];
			}
			return;
		}
		int mid = lx + (rx - lx) /2;
		build(a, 2*x+1, lx, mid);
		build(a, 2*x+2, mid, rx);
		vec[x] = min(vec[2*x+1],vec[2*x + 2]);
	}
	void build(const vector<int> &a) {
		build(a, 0, 0, size);
	}
	ll query(int l, int r, int x, int lx, int rx) {
		if(lx >= r || l >= rx) return inf;
		if(lx >= l && rx <= r) return vec[x];
		int mid = lx + (rx - lx) / 2;
		int ql = query(l, r, 2*x+1, lx, mid);
		int qr = query(l, r, 2*x+2, mid, rx);
		return min(ql, qr);
	}

	ll query(int l, int r) {
		return query(l, r, 0, 0, size);
	}
};


void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	cout << m << endl;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(!a[i]) a[i] = inf;
		cout << a[i] << ' ';
	}
	cout << endl;
	segtree seg;
	seg.init(n);
	seg.build(a);
	int ans = 0;
	int tempm = m;
	bool impos = false;
	for(int i = 0; i < n; i++) {
		int rn = seg.query(i, i+m);
		int should = seg.query(i+m, min(n-1, i+2*m));
		if(should == inf) {

		}
	}
	if(!impos)
		cout << ans << endl;
	else
		cout << -1 << endl;
	return;
}

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		cout << "Case #" << tt << ": ";
		solve();
	}

	return 0;
}
