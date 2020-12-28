/*
	author: Creepysta
	10-10-2020 19:40:25
*/
// https://en.m.wikipedia.org/wiki/Widest_path_problem

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

struct Edge {
	int weight;
	int u, v;
	bool operator<(const Edge& e) {
		return weight < e.weight;
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int> (m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	vector<Edge> edges;
	vector<vector<bool>> vis(n, vector<bool> (m, false));
	auto valid = [&](int x, int y) {
		return (x >= 0 && x < n) && (y >= 0 && y < m);
	};
	auto trans = [&](int x, int y) {
		return x*m + y;
	};
	vector<pair<int, int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	for(int row = 0; row < n; row ++) {
		for(int col = 0; col < m; col++) {
			for(pair<int, int> p : dirs) {
				int i = p.first, j = p.second;
				int x = row + i, y = col + j;
				if(valid(x, y) && (!vis[row][col] && !vis[x][y])) {
					//cout << row << ',' << col << '-' << x << ',' << y << '=' << trans(row, col) << '-' << trans(x, y) << endl;
					Edge e1 = {abs(a[row][col] - a[x][y]), trans(row, col), trans(x, y)};
					Edge e2 = {abs(a[row][col] - a[x][y]), trans(x, y), trans(row, col)};
					edges.push_back(e1);
					//edges.push_back(e2);
				}
			}
			vis[row][col] = true;
		}
	}
	sort(edges.rbegin(), edges.rend());
	vector<int> tree(n*m);
	for(int i = 0; i < n*m; i++) {
		tree[i] = i;
	}
	int cost = 0;
	vector<tuple<int, int, int>> res;
	for(Edge e : edges) {
		if(tree[e.u] != tree[e.v]) {
			cost += e.weight;
			res.push_back({e.u, e.v, e.weight});
			int old = tree[e.u], now = tree[e.v];
			for(int i = 0; i < n*m; i++) {
				if(tree[i] == tree[old])
					tree[i] = now;
			}
		}
		cout << e.u << '-' << e.v << " = " << e.weight << ',' << cost << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

