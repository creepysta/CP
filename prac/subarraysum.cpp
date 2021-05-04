/*
	author: Creepysta
	02-04-2021 12:38:56
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

void solve() {
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for(int &i : a)
		cin >> i;
	int sum = 0;
	debug(n, s, a)
	vector<int> pref(n,a[0]);
	for(int i = 1; i < n; i++)
		pref[i] = pref[i-1] + a[i];
	for(int i = 0, j = -1; i < n; ) {
		int sub = j == -1 ? 0 : pref[j];
		int got = pref[i] - sub;
		//if(sum == s) {
		if(got == s) {
			debug("got", sub, got, i, j)
			cout << i << ' ' << j << '\n';
			return;
		//} else if (sum < s) {
		} else if (got < s) {
			i++;
		} else
			j++;
		debug(sub, got, i, j)
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

