/*
	author: Creepysta
	14-05-2021 13:21:56
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
#define itfr { if(x.empty()) {cout<<"[ ]";return o;} o<<"[";for(auto e:x) o<<e<<", ";o<<"\b\b]";return o;}
void err(istream_iterator<string> it) {cerr<<"\b\b ]\n";}
tmpt , class... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr<<*it<<": "<<a<< ", ";err(++it,args...);}
tmpt > ostop , const vector<T> &x) itfr
tmpt > ostop , const set<T> &x) itfr
tmpt > ostop , const multiset<T> &x) itfr
tmpt , class V> ostop , const map<T,V> &x) itfr
tmpt , class V> ostop , const pair<T,V> &p) {o<<"(";o<<p.first<<", "<<p.second<<")";return o;}

#define ff first
#define ss second
typedef pair<int, int> pii;

vector<vector<pii>> g;

struct LCA {
	vector<int> depth;
	vector<vector<int>> par, maxd, mind;
	int LOG, n;
	const int nax = 1e12;
	LCA() {
		n = g.size();
		LOG = ceil(log2(n)) + 1;
		depth.resize(n);
		par.resize(n, vector<int> (LOG));
		maxd.resize(n, vector<int> (LOG, -nax));
		mind.resize(n, vector<int> (LOG, nax));
		dfs(make_pair(0, 0), 0);
	}
	void dfs(pii e, int p = -1) {
		par[e.ff][0] = p;
		depth[e.ff] = depth[p] + 1;
		mind[e.ff][0] = maxd[e.ff][0] = e.ss;
		for(int j = 1; j < LOG; j++) {
			par[e.ff][j] = par[par[e.ff][j-1]][j-1];
			mind[e.ff][j] = min(mind[e.ff][j-1],
					mind[par[e.ff][j-1]][j-1]);
			maxd[e.ff][j] = max(maxd[e.ff][j-1],
					maxd[par[e.ff][j-1]][j-1]);
		}
		for(auto ve : g[e.ff]) {
			if(ve.ff != p)
				dfs(ve, e.ff);
		}
	}
	pii get(int a, int b) {
		if(depth[a] > depth[b]) {
			swap(a, b);
		}
		// 1) Get same depth.
		int k = depth[b] - depth[a], big = -nax, small = nax;
		for(int j = LOG - 1; j >= 0; j--) {
			if(k & (1 << j)) {
				big = max(big, maxd[b][j]);
				small = min(small, mind[b][j]);
				b = par[b][j]; // parent of a
			}
		}
		// 2) if b was ancestor of a then now a==b
		if(a == b) {
			return {small, big};
		}
		// 3) move both a and b with powers of two
		for(int j = LOG - 1; j >= 0; j--) {
			if(par[a][j] != par[b][j]) {
				big = max(big, max(maxd[b][j], maxd[a][j]));
				small = min(small, min(mind[b][j], mind[a][j]));
				a = par[a][j];
				b = par[b][j];
			}
		}
		big = max(big, max(maxd[b][0], maxd[a][0]));
		small = min(small, min(mind[b][0], mind[a][0]));
		return {small, big};
	}
};

void solve() {
	int n, q;
	cin >> n;
	g.resize(n);
	for(int i = 0; i < n-1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	LCA lca;
	cin >> q;
	debug(n, q);
	while(q--) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		auto ans = lca.get(u, v);
		cout << ans.ff << " " << ans.ss << "\n";
	}
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

