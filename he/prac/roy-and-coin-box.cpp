/*
	author: Creepysta
	16-05-2021 20:01:00
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9) + 7;
#define int int64_t
#ifdef LOCAL
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << boolalpha << "debug: [ "; err(_it, args); }
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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n+2);
	int m;
	cin >> m;
	for(int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		a[l]++, a[r+1]--;
	}
	vector<int> b(n, MOD);
	for(int i = 1; i <= n; i++) {
		a[i] += a[i-1];
		b[i-1] = a[i];
	}
	sort(b.begin(), b.end());
	int q;
	cin >> q;
	while(q--) {
		int p;
		cin >> p;
		int got = lower_bound(b.begin(), b.end(), p) - b.begin();
		int ans = n-got;
		cout << ans << "\n";
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
