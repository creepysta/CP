/*
https://www.spoj.com/problems/GERGOVIA/
	author: Creepysta
	21-05-2021 01:34:12
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int MOD = int(1e9) + 7;
#ifdef LOCAL
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << boolalpha << "[ "; err(_it, args); }
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

int n;
void solve() {
	typedef pair<int,int> pii;
#define F first
#define S second
	int ans = 0;
	vector<pii> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i].S;
		a[i].F = i;
	}
	sort(a.begin(), a.end(), [](const pii & p1, const pii &p2) {
			return p1.S < p2.S;
			});
	int x = 0;
	for(int i = 0; i < n; i++) {
		if(a[i].S < 0)
			x++;
	}
	debug(a, x);
	sort(a.begin(), a.begin()+x);
	sort(a.begin() + x, a.end());
	debug(n, a);
	int i = 0, j = x;
	while(1) {
		if(a[i].S == 0) i++;
		if(a[j].S == 0) j++;
		if(i == x || j == n)
			break;
		int smol = min(-a[i].S, a[j].S), diff = abs(a[i].F - a[j].F);
		a[i].S += smol;
		a[j].S -= smol;
		debug(smol, diff);
		ans += diff * smol;
	}
	cout << ans << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int x;
	cin >> x;
	int now = 0;
	for(; !(x==0 && now % 2 == 0); ) {
		// cout << "Case #" << tt << ": ";
		n = x;
		solve();
		now+=2;
		cin >> x;
	}
	return 0;
}

