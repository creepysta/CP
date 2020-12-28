/*
	author: Creepysta
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct node {
	int y, x;
	node() {}
	node (int _y, int _x) : y(_y), x(_x) {}
};

void solve() {
	int n, m;
	cin >> n >> m;
	int s1, s2, t1, t2;
	cin >> s1 >> s2 >> t1 >> t2;
	vector<vector<char>> g(n, vector<char> (m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> g[i][j];
		}
	}
	bool visited[n][m];
	memset(visited, 0, sizeof(visited));
	queue<node> q;
	q.push(node(s1, s2));
	auto safe = [&] (int x, int y) {
		bool boundary = (x >= 0 || x < m) && (y >= 0 || y < n);
		bool wall = g[x][y] == '.';
		return boundary && wall;
	}
	while(!q.empty()) {
		node cn = q.front();
		q.pop();
		for(int row : {0, 0, -1, 1}) {
			for(int col : {-1, 1, 0, 0}) {
				int cr = cn.y + row,
					cc = cn.x + col;
				if(safe(cr ,cc) && !visited[cr][cc]) {
					q.push(node(cr, cc));
				}
			}
		}
	}

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

