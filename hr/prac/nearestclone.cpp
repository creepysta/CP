/*
author: Creepysta
21-11-2020 12:25:20
*/
// 1 -1 3
#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e9) + 7;

vector<vector<int>> g;
vector<bool> vis;

int bfs(int u, int id, const vector<int> &ids) {
	queue<pair<int, int>> q;
	q.push({u, 0});
	vis[u] = 1;
	while(!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();
		for(int v : g[curr.first]) {
			if(!vis[v]) {
				if(ids[u] == ids[v])
					return curr.second + 1;
				q.push({v, curr.second + 1});
				vis[v] = 1;
			}
		}
	}
	return INT_MAX;
}


void solve() {
	int n, m, id;
	cin >> n >> m;
	g.resize(n);
	vis.assign(n, 0);
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector<int> ids(n);
	for(int &i : ids)
		cin >> i;
	cin >> id;
	int dist = INT_MAX;
	for(int i = 0; i < n; i++) {
		if(ids[i] == id) {
			vis.assign(n, false);
			dist = min(dist, bfs(i, id, ids));
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
		vis.clear();
		solve();
		auto t2 = chrono::high_resolution_clock::now();
		auto span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
		// cout << "TIME TAKEN " << span.count() << " secs" << endl;
	}
	return 0;
}

