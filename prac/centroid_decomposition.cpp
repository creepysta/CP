#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9) + 7;
#ifdef LOCAL
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << "debug: [ "; err(_it, args); }
#else
#define debug(args...) 0;
#endif
#define tmpt template < class T
#define ostop ostream& operator<<(ostream& o
#define itfr { if(!x.empty()) o << "[";for(auto e : x) o << e << ", "; o<<"\b\b]"; return o;}
void err(istream_iterator<string> it) { cerr << "\b\b ]\n";}
tmpt , class... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << ": " << a << ", "; err(++it, args...); }
tmpt > ostop , const vector<T> &x) itfr
tmpt > ostop , const set<T> &x) itfr
tmpt , class V> ostop , const map<T,V> &x) itfr
tmpt , class V> ostop , const pair<T,V> &p) { o << "(";o << p.first << ", " << p.second << ")"; return o;}

struct Centroid {
	vector<vector<int>> t, g, dist;
	vector<int> sub, par, level;
	vector<bool> deleted;
	int n, sz, LOG;
	Centroid(const vector<vector<int>> &a) : n(a.size()), g(a) {
		t.resize(n);
		deleted.assign(n, false);
		LOG = ceil(log2(n));
		// dist[LOGN][n] : dist[l][x] : Distance between C and X in the original tree when C becomes the Centroid at level "l";
		dist.resize(LOG, vector<int> (n));
		decompose(0);
	}
	void dfs(int u, int p = -1) {
		sub[u] = 1;
		sz++;
		for(int v : g[u]) {
			// TODO: reconsider how to delete
			if(v != p && !deleted[v]) {
				dfs(v, u);
				sub[u] += sub[v];
			}
		}
	}
	void find_centroid(int u, int p) {
		for(int v : g[u]) {
			if(deleted[v]) continue;
			if(v != p && sub[v] > nn / 2)
				return find_centroid(v, u);
		}
		return u;
	}
	void add_edge(int parent, int child) {
		par[child] = parent;
		level[child] = level[parent] + 1;
	}
	void dfs2(int u, int p, int lvl) {
		for(int v : g[u]) {
			if(v == p || deleted[v]) continue;
			dist[lvl][w] = dist[lvl][u] + 1;
			dfs2(v, u, lvl);
		}
	}
	void decompose(int root, int p = -1) {
		sz = 0;
		dfs(root, root);
		int centroid = find_centroid(root, root);
		if(p == -1) p = root;
		add_edge(p, centroid);
		dfs2(centroid, centroid, level[centroid]);
		for(int v : g[centroid]) {
			if(deleted[v]) continue;
			deleted[v] = 1;
			decompose(v, centroid);
		}
	}
};

int main() {
	int n;
	for(int i = 1; i < n; i++) {
		int x, int y;
		cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	return 0;
}
