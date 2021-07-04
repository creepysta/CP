/*
	author: Creepysta
	12-05-2021 19:51:30
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
#define itfr { if(!x.empty()) o << "[";for(auto e : x) o << e << ", "; o<<"\b\b]"; return o;}
void err(istream_iterator<string> it) { cerr << "\b\b ]\n";}
tmpt , class... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << ": " << a << ", "; err(++it, args...); }
tmpt > ostop , const vector<T> &x) itfr
tmpt > ostop , const set<T> &x) itfr
tmpt > ostop , const multiset<T> &x) itfr
tmpt , class V> ostop , const map<T,V> &x) itfr
tmpt , class V> ostop , const pair<T,V> &p) { o << "(";o << p.first << ", " << p.second << ")"; return o;}

/*
 * given intervals parallel to x axis
 * find the min vertical lines to cut all the intervals
 *
 * */

struct Pt {
	int a, b;
	void read() {
		cin >> a >> b;
	}
	bool operator < (const Pt &p) {
		return a <= p.a;
	}
	friend ostream& operator << (ostream &o, const Pt &p) {
		cout << make_pair(p.a, p.b);
		return o;
	}
};

bool overlaps(Pt& p, Pt &q) {
	for(int rep = 0; rep < 2; rep++) {
		if((p.a <= q.a && q.a <= p.b) ||
				(p.a <= q.b && q.b <= p.b))
					return true;
		swap(p, q);
	}
	return false;
}

void solve() {
	int n;
	cin >> n;
	vector<Pt> a(n);
	for(int i = 0; i < n; i++) {
		a[i].read();
	}
	sort(a.begin(), a.end());
	vector<bool> got(n);
	bool taken = false;
	int ans = 0;
	for(int i = 0, j = 0; i < n && j < n;) {
		taken = false;
		while(i < n && got[i])
			i++;
		j = i;
		while(j < n && overlaps(a[i], a[j])) {
			if(!taken) ans++;
			taken = true;
			got[j] = taken;
			j++;
		}
	}
	cout << ans << '\n';
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

