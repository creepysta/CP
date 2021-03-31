/*
	author: Creepysta
	27-03-2021 12:29:27
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9) + 7;
#define int int64_t
#ifdef LOCAL
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << "debug: [ "; err(_it, args); }
#else
#define debug(args...) 0
#endif
#define tmpt template < class T
#define ostop ostream& operator<<(ostream& o
#define itfr { o << "[";for(auto e : v) o << e << ", "; o<<"\b\b]"; return o;}
void err(istream_iterator<string> it) { cerr << "\b\b ]\n";}
tmpt , class... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << ": "  << a << ", "; err(++it, args...); }
tmpt > ostop , const vector<T> &v) itfr
tmpt > ostop , const set<T> &v) itfr
tmpt , class V> ostop , const map<T,V> &v) itfr
tmpt , class V> ostop , const pair<T,V> &p) { o << "(";o << p.first << ", " << p.second << ")"; return o;}

void solve() {
	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<int> a(k);
	for(int &i : a)
		cin >> i;
	for(int mask = 0; mask < (1<<k); mask++) {
		int lhs = 0;
		for(int i = 0; i < k; i++) {
			if(mask & i) {
				a[i]*x + a[y]
			}
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

