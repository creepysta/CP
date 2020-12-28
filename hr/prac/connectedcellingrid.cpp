/*
	author: Creepysta
	21-11-2020 19:00:09
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e9) + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int> (m));
	vector<vector<bool>> vis(n, vector<bool> (m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	auto valid = [&] (int i, int j) {
		if(i >= 0 && i < n && j >= 0 && j < m)
			return 1;
		return 0;
	};
	auto bfs = [&] (int i, int j) {
		int area = 1;
		queue<pair<int, int>> q;
		q.push({i, j});
		vis[i][j] = 1;
		while(!q.empty()) {
			pair<int, int> ver = q.front();
			q.pop();
			for(int dx : {-1, 1, 0}) {
				for(int dy : {-1, 1, 0}) {
					if(dx || dy) {
						int x = ver.first + dx,
							y = ver.second + dy;
						if(valid(x, y) && a[x][y] == 1 && !vis[x][y]) {
							area++;
							vis[x][y] = 1;
							q.push({x, y});
						}
					}
				}
			}
		}
		return area;
	};
	int big = -1e9;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == 1 && !vis[i][j]) {
				big = max(big, bfs(i, j));
			}
		}
	}
	cout << big << '\n';
	return 0;
}

