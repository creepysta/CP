#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& parent, int x) {
	if(parent[x] == -1)
		return x;
	return find(parent, parent[x]);
}

void Union(vector<int> &parent, int x, int y) {
	int a = find(parent, x);
	int b = find(parent, y);
	if(a != b)
		parent[a] = b;
}

bool detectCycle(const vector<pair<int, int>>& g, vector<int>& parent) {
	for(int i = 0; i < (int) g.size(); i++) {
		int x = find(parent, g[i].first);
		int y = find(parent, g[i].second);
		if(x == y)
			return 1;
		Union(parent, x, y);
	}
	return 0;
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> g(n);
	vector<int> parent(n,-1), sets(n);
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[i] = make_pair(x, y);
	}
	cout << detectCycle(g, parent) << endl;
	return 0;
}
