/*
author: Creepysta
21-11-2020 12:25:20
*/
// 1 -1 3
#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e9) + 7;

vector<vector<int>> g;
vector<int> first, euler, height;
vector<bool> vis;

void dfs(int u, int h = 0) {
	vis[u] = 1;
	height[u] = h;
	first[u] = euler.size();
	euler.push_back(u);
	for(int v : g[u]) {
		if(!vis[v]) {
			dfs(v, h+1);
			euler.push_back(u);
		}
	}
}

struct seg {
	vector<int> tree;
	int n = 1;
	seg(const vector<int> &a) {
		while(n < (int) a.size())
			n <<= 1;
		tree.resize(2 * n);
		build(a, 1, 0, n-1); 
	}
	void build(const vector<int> &a, int x, int l, int r) {
		if(l == r) {
			if(l < (int) a.size())
				tree[x] = a[l];
			return;
		}
		int mid = l + (r-l) / 2;
		build(a, x << 1, l, mid);
		build(a, x << 1 | 1, mid+1, r);
		int left = tree[2*x], right = tree[2*x + 1];
		tree[x] = height[left] < height[right] ? left : right;
	}
	int query(int x, int lx, int rx, int l, int r) {
		if(lx > r || rx < l) return -1;
		if(lx <= l && rx >= r) return tree[x];
		int mid = l + (r-l) / 2;
		int left = query(x << 1, lx, rx, l, mid);
		int right = query(x << 1 | 1, lx, rx, mid + 1, r);
		if(left == -1)
			return right;
		if(right == -1)
			return left;
		return height[left] < height[right] ? left : right;
	}
	int query(int l, int r) {
		return query(1, l, r, 0, n-1);
	}
};

void solve() {
	int n, m, id;
	cin >> n >> m;
	g.resize(n);
	vis.assign(n, 0);
	height.resize(n);
	first.resize(n);
	euler.reserve(2*n);
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	map<int, vector<int>> ids;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ids[x].push_back(i);
	}
	cin >> id;
	dfs(0);
	seg s(euler);
	int dist = INT_MAX;
	for(int i = 0; i < (int) ids[id].size(); i++) {
		for(int j = i + 1; j < (int) ids[id].size(); j++) {
			int u = ids[id][i], v = ids[id][j];
			int left = first[u], right = first[v];
			if (left > right)
				swap(left, right);
			int lca = s.query(left, right);
			if(lca == -1)
				continue;
			// cerr << "DEBUG: " << lca << " " << u << " " << v << " " << height[u] << " " << height[v] << " " << height[lca] << endl;
			dist = min(dist, height[u] + height[v] - 2 * height[lca]);
		}
	}
	if(dist == INT_MAX)
		cout << -1 << '\n';
	else 
		cout << dist << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T = 1;
	cin >> T;
	for(int tt = 1; tt <= T; tt++) {
		auto t1 = chrono::high_resolution_clock::now();
		g.clear();
		first.clear();
		euler.clear();
		height.clear();
		vis.clear();
		solve();
		auto t2 = chrono::high_resolution_clock::now();
		auto span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
		cout << "TIME TAKEN " << span.count() << " secs" << endl;
	}
	return 0;
}

