/*
	author: Creepysta
01-05-2021 19:33:17
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

/* techgig - cognizant
 * given string S and q strings qs check if qs is a subsequence of string S
 *
 */
void solve() {
	string v;
	cin >> v;
	int q;
	cin >> q;
	while(q--) {
		string s;
		cin >> s;
		int n = v.length(), m = s.length(), i = 0, j = 0;
		for(; i < n && j < m; ) {
			if(v[i] == s[j])
				i++, j++;
			else
				i++;
		}
		if(j == m)
			cout << "POSITIVE\n";
		else
			cout << "NEGATIVE\n";
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

