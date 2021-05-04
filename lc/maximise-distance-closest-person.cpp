/*
	author: Creepysta
	20-04-2021 01:22:58
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
#define itfr { o << "[";for(auto e : x) o << e << ", "; o<<"\b\b]"; return o;}
void err(istream_iterator<string> it) { cerr << "\b\b ]\n";}
tmpt , class... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << ": "  << a << ", "; err(++it, args...); }
tmpt > ostop , const vector<T> &x) itfr
tmpt > ostop , const set<T> &x) itfr
tmpt , class V> ostop , const map<T,V> &x) itfr
tmpt , class V> ostop , const pair<T,V> &p) { o << "(";o << p.first << ", " << p.second << ")"; return o;}

int solve(const vector<int> &a) {
	int n = a.size(), pos = -1;
	for(int i = 0; i < n; i++) {
		int j = i, k = i, pp = -1;
		debug(i, j, k);
		if(a[i] == 0) {
			while(j >= 0 && !a[j])
				j--;
			while(k < n && !a[k])
				k++;
			j = j < 0 ? 0 : j;
			k = k > n-1 ? n-1 : k;
			debug(j, k);
			pp = (k - j);
			if(a[j] && a[k])
				pp /= 2;
			pos = max(pp, pos);
		}
		i = k;
	}
	return pos;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		vector<vector<int>> a = {{1,0,0,0,1,0,1}, {1,0,0,0}, {0,1}, {0,0,1}};
		for(auto &v : a) {
			debug(v);
			cout << solve(v) << '\n';
		}
	}
	return 0;
}

