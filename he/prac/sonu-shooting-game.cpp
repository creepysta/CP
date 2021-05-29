/*
	author: Creepysta
	26-05-2021 20:34:00
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9) + 7;
#define int int64_t
#ifdef LOCAL
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << boolalpha << "[ "; err(_it, args); }
#else
#define debug(args...) ;
#define FIO ;
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

vector<vector<double>> dp;
int x, y;
double p1, p2;

double f (int n, int w) {
	if(w <= 0)
		return 1.0;
	if(n == 0)
		return 0.0;
	if(dp[n][w] != -1.0)
		return dp[n][w];
	return dp[n][w] = max(
			f(n-1, w-x) * p1 + f(n-1, w) * (1-p1),
			f(n-1, w-y) * p2 + f(n-1, w) * (1-p2)
			);
}

void solve() {
	int n, w;
	cin >> x >> y >> n >> w >> p1 >> p2;
	p1 /= 100.0, p2 /= 100.0;
	double ans = f(n, w) * 100.0;
	cout << setprecision(6) << fixed << ans << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		dp = vector<vector<double>> (1010, vector<double> (1010, -1.0));
		solve();
	}
	return 0;
}

