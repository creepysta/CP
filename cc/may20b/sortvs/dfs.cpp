/*
	author: Creepysta
	25-09-2020 13:08:25
*/
#include <bits/stdc++.h>
using namespace std;
/*
2
5
1 2
1 3
2 5
3 4
4 2
5
1 2
1 3
2 5
3 4
3 5
 *
 *	1 - 2 - 5
 *	|	|
 *	3 - 4
 *
 *	1 - 2-->
 *	|		|
 *	3 - 4	|
 *	|		|
 *	5<------
 *
 * */
const int MOD = 1e9 + 7;
vector<bool> vis;

void dfs(const vector<vector<int>> &g, int parent) {
	vis[parent] = 1;
	cout << (parent + 1) << ' ';
	for(int child : g[parent]) {
		if(!vis[child]) {
			dfs(g, child);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> g(n);
		vis.clear(); vis.resize(n);
		while(n--) {
			int x, y;
			cin >> x >> y;
			x--, y--;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(g, 0);
		cout << endl;
	}
	return 0;
}

