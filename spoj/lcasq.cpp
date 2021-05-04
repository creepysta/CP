/*
	author: Creepysta
	08-04-2021 21:25:30
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9) + 7;
#define int int64_t
#ifdef LOCAL
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << "debug: [ "; err(_it, args); }
#else
#define debug(args...) 0;
#endif
#define tmpt template < class T
#define ostop ostream& operator<<(ostream& o
#define itfr { o << "[";for(auto e : x) o << e << ", "; o<<"\b\b]"; return o;}
void err(istream_iterator<string> it) { cerr << "\b\b ]\n";}
tmpt , class... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << ": "  << a << ", "; err(++it, args...); }
tmpt > ostop , const vector<T> &x) itfr
tmpt > ostop , const set<T> &x) itfr
tmpt , class V> ostop , const map<T,V> &x) itfr
tmpt , class V> ostop , const pair<T,V> &p) { o << "(";o << p.first << ", " << p.second << ")"; return o;}

struct LCA {
	vector<int> height, first, euler, seg;
	vector<bool> vis;
	int m = 0;
	LCA(const vector<vector<int>> &g, int root = 0) {
		int n = g.size();
		height.resize(n);
		first.resize(n);
		euler.reserve(2*n);
		vis.assign(n, false);
		dfs(g, root);
		m = euler.size();
		seg.resize(m * 4);
		build(1, 0, m-1);
	}
	void dfs(const vector<vector<int>> &g, int u, int h = 0) {
		vis[u] = 1;
		height[u] = h;
		first[u] = euler.size();
		euler.push_back(u);
		for(int v : g[u]) {
			if(!vis[v]) {
				dfs(g, v, h+1);
				euler.push_back(u);
			}
		}
	}
	void build(int x, int lx, int rx) {
		if(lx == rx) {
			seg[x] = euler[lx];
			return;
		}
		int mid = (lx + rx)/2;
		build(2*x, lx, mid);
		build(2*x + 1, mid + 1, rx);
		int left = seg[2*x], right = seg[2*x + 1];
		seg[x] = height[left] < height[right] ? left : right;
	}
	int query(int l, int r, int x, int lx, int rx) {
		if(l > rx || r < lx) return -1;
		if(l <= lx && rx <= r) return seg[x];
		int mid = (lx + rx) / 2;
		int left = query(l, r, 2*x, lx, mid);
		int right = query(l, r, 2 * x + 1, mid + 1, rx);
		if(left == -1) return right;
		if(right == -1) return left;
		return height[left] < height[right] ? left : right;
	}
	int lca(int u, int v) {
		int left = first[u], right = first[v];
		if(left > right)
			swap(left, right);
		return query(left, right, 1, 0, m-1);
	}
};

void solve() {
	int n, m, q, x, y;
	cin >> n;
	vector<vector<int>> g(n);
	for(int i = 0; i < n; i++) {
		cin >> m;
		while(m--) {
			cin >> x;
			g[i].push_back(x);
		}
	}
	cin >> q;
	LCA lca(g);
	while(q--) {
		cin >> x >> y;
		int got = lca.lca(x, y);
		cout << got << '\n';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

