//check for bipartite graph
/*
	author: Creepysta
02-05-2021 12:10:54
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

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector<int> side(n, -1);
	bool is = true;
	for(int i = 0; i < n; i++) {
		if(side[i] == -1) {
			queue<int> q;
			q.push(i);
			side[i] = 0;
			while(q.size()) {
				int u = q.front();
				q.pop();
				for(int v : g[u]) {
					if(side[v] == -1) {
						side[v] = side[u] ^ 1;
						q.push(v);
					}
					else
						is &= side[v] != side[u];
				}
			}
		}
	}
	if(is)
		cout << "No suspicious bugs found!\n";
	else
		cout << "Suspicious bugs found!\n";
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		cout << "Scenario #" << tt << ":\n";
		solve();
	}
	return 0;
}

