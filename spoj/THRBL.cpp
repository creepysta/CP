//catapult the ball
/*
	author: Creepysta
	16-05-2021 16:36:51
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
int logdp[MAX_N];

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> h(n);
	memset(ST, -MOD - 5, sizeof(ST));
	for(int i = 0; i < n; i++) {
		cin >> h[i];
		ST[i][0] = h[i];
	}
	int ans = 0;
	for(int j = 1; j <= LOG; j++) {
		for(int i = 0; i + (1<<j) <= n; i++) {
			ST[i][j] = max(ST[i][j-1], ST[i+(1<<(j-1))][j-1]);
		}
	}
	logdp[0] = logdp[1] = 0;
	for(int i = 2; i <= n; i++)
		logdp[i] = logdp[i/2] + 1;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if(abs(v-u) <= 1) {
			ans++;
			continue;
		}
		u--, v--;
		int l = u + 1, r = v-1;
		if(l > r)
			swap(l, r);
		int len = r - l + 1;
		int j = logdp[len];
		int tall = max(ST[l][j], ST[r - (1<<j) + 1][j]);
		debug(u, v, l, r, tall);
		if(tall <= h[u])
			ans ++;
	}
	cout << ans << "\n";
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

