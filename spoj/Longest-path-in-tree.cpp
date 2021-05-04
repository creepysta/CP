/*
	author: Creepysta
	02-05-2021 21:46:31
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
#define itfr { if(x.empty()) return o; o << "[";for(auto e : x) o << e << ", "; o<<"\b\b]"; return o;}
void err(istream_iterator<string> it) { cerr << "\b\b ]\n";}
tmpt , class... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << ": " << a << ", "; err(++it, args...); }
tmpt > ostop , const vector<T> &x) itfr
tmpt > ostop , const set<T> &x) itfr
tmpt , class V> ostop , const map<T,V> &x) itfr
tmpt , class V> ostop , const pair<T,V> &p) { o << "(";o << p.first << ", " << p.second << ")"; return o;}

vector<vector<int>> g;
vector<bool> vis;
int big, ver;

void dfs(int u, int h = 0) {
	vis[u] = 1;
	if(h > big) {
		big = h;
		ver = u;
	}
	for(int v : g[u]) {
		if(!vis[v]) {
			dfs(v, h+1);
		}
	}
}


void solve() {
	int n;
	cin >> n;
	g.resize(n);
	vis.assign(n, false);
	for(int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	big = -1;
	dfs(0);
	debug(big, ver);
	big = -1;
	vis.assign(n, false);
	dfs(ver);
	debug(big, ver);
	cout << big << '\n';
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

