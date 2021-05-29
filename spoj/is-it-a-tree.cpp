/*
	author: Creepysta
	17-05-2021 19:39:09
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9) + 7;
#define int int64_t
#ifdef LOCAL
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << boolalpha << "[ "; err(_it, args); }
#else
#define debug(args...) 0;
#endif
#define tmpt template < class T
#define ostop ostream& operator<<(ostream& o
#define itfr { if(x.empty()) {cout<<"[ ]";return o;} o<<"[";for(auto e:x) o<<e<<", ";o<<"\b\b]";return o;}
void err(istream_iterator<string> it) {cerr<<"\b\b ]\n";}
tmpt , class... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr<<*it<<": "<<a<< ", ";err(++it,args...);}
tmpt > ostop , const vector<T> &x) itfr
tmpt > ostop , const set<T> &x) itfr
tmpt > ostop , const multiset<T> &x) itfr
tmpt , class V> ostop , const map<T,V> &x) itfr
tmpt , class V> ostop , const pair<T,V> &p) {o<<"(";o<<p.first<<", "<<p.second<<")";return o;}

vector<vector<int>> g, comp;
vector<int> curr;
vector<bool> vis;
bool backedge;

void dfs(int u, int p = -1) {
	vis[u] = 1;
	curr.push_back(u);
	for(int v : g[u]) {
		if(!vis[v])
			dfs(v, u);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	g.clear();
	g.resize(n);
	backedge = 0;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vis.assign(n, false);
	comp.clear();
	for(int i = 0; i < n; i++) {
		curr.clear();
		if(!vis[i])
			dfs(i);
		if(curr.size())
			comp.push_back(curr);
	}
	debug(comp, n, m, backedge);
	if(comp.size() == 1 && m == n-1 && !backedge)
		cout << "YES\n";
	else
		cout << "NO\n";
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

