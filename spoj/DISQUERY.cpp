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
#define pii pair<int, int>

vector<pii> g;

struct LCA {
	vector<int> depth;
	vector<vector<int>> par;
	int LOG, n;
	void dfs(int u, int p = -1) {
		for(auto v : g[u]) {

		}
	}
};

void solve() {
	int n, q;
	cin >> n;
	g.resize(n);
	for(int i = 0; i < n-1; i++) {
		int v, w;
		cin >> v >> w;
		g[i].emplace_back(v, w);
	}
	cin >> q;
	while(q--) {
		int u, v;
		cin >> u >> v;
		// find shortest and longest path between them
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

