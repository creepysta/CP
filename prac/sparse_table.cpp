/*
	author: Creepysta
	16-05-2021 13:42:41
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

const int MAX_N = 1e6 + 5;
const int LOG = 18;
int ST[MAX_N][LOG];

void solve() {
	int n;
	cin >> n;
	vector<int> a(n+1);
	memset(ST, MOD + 5, sizeof(ST));
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		ST[i][0] = a[i];
	}
	for(int j = 1; j <= LOG; j++) {
		for(int i = 0; i + (1 << j) <= n; i++) {
			ST[i][j] = min(ST[i][j-1], ST[i+(1<<(j-1))][j-1]);
		}
	}
	vector<int> logs(n+1);
	for(int i = 2; i <= n; i++)
		logs[i] = logs[i/2] + 1;
	int q;
	cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r;
		int len = r - l + 1;
		int j = logs[len];
		int ans = min(ST[l][j], ST[r-(1<<j)+1][j]);
		cout << ans << '\n';
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

