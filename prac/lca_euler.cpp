#include <bits/stdc++.h>
using namespace std;

struct LCA {
	vector<int> height, euler, first, seg;
	vector<bool> vis;
	int n;
	LCA(const vector<vector<int>> &a, int root = 0) {
		n = a.size();
		height.resize(n);
		first.resize(n);
		vis.assign(n, 0);
		euler.reserve(2*n);
		dfs(a, root);
		int m = euler.size();
		seg.resize(4*m);
		build(1, 0, m-1);
	}
	void dfs(const vector<vector<int>> &a, int u, int h = 0)  {
		vis[u] = 1;
		height[u] = h;
		first[u] = euler.size();
		euler.push_back(u);
		for(int v : a[u]) {
			if(!vis[v]) {
				dfs(a, v, h+1);
				euler.push_back(u);
			}
		}
	}
	void build(int x, int l, int r) {
		if(l == r) {
			seg[x] = euler[l];
			return;
		}
		int m = (l+r)/2;
		build(2*x, l, m);
		build(2*x + 1, m + 1, r);
		int left = seg[2*x], right = seg[2*x + 1];
		seg[x] = height[left] < height[right] ? left : right;
	}
	int query(int x, int l, int r, int lx, int rx) {
		if(l > r) return -1;
		if(l > rx || r < lx) return -1;
		if(lx <= l && r <= rx) return seg[x];
		int m = (l + r) / 2;
		int left = query(2*x, l, m, lx, rx);
		int right = query(2*x + 1, m+1, r, lx, rx);
		if(left == -1) return right;
		if(right == -1) return left;
		return height[left] < height[right] ? left : right;
	}
	int query(int lx, int rx) {
		return query(1, 0, euler.size()-1, lx, rx);
	}
	int lca(int u, int v) {
		int left = first[u], right = first[v];
		if(left > right) 
			swap(left, right);
		return query(left, right);
	}
};

void solve() {
	int n, m, x, q, l, r;
	cin >> n;
	vector<vector<int>> a(n);
	for(int i = 0; i < n; i++) {
		cin >> m;
		for(int j = 0; j < m; j++) {
			cin >> x; x--;
			a[i].push_back(x);
			a[x].push_back(i);
		}
	}
	LCA lca(a, 0);
	cin >> q;
	for(int i = 0; i < q; i++) {
		cin >> l >> r; l--; r--;
		int ans = lca.lca(l, r); ans++;
		cout << ans << '\n';
	}
}

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cout << "Case " << t << ":\n";
		solve();
	}
	return 0;
}
