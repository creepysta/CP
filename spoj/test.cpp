/*
	author: Creepysta
	23-05-2021 12:59:13
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int MOD = int(1e9) + 7;
const int INF = int(1e12) + 5;
#ifdef LOCAL
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << boolalpha << "debug: [ "; err(_it, args); }
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

int n, c;
vector<int> a;
vector<pair<int, int>> pos;

bool put(int dist) {
	int prev = a[0], placed = 1;
    pos.clear();
    pos.emplace_back(0, a[0]);
    bool ok = 0;
	for(int i = 1; i < n; i++) {
		if(a[i] - prev >= dist) {
			prev = a[i];
			placed ++;
            pos.emplace_back(i, a[i]);
		}
		if(placed == c)
			ok = 1;
	}
    int ans = dist;
    debug(dist, pos, placed, ans);
	return ok;
}

void solve() {
	cin >> n >> c;
	a = vector<int> (n);
    debug(n, c);
	for(int & i : a)
		cin >> i;
	sort(a.begin(), a.end());
	int lo = a[0], hi = a[n-1], mind = -1;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if(put(mid)) {
			mind = mid;
			lo = mid + 1;
		}
		else
			hi = mid - 1;
	}
	cout << mind << "\n";
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

// ABCDEF
// 4 sum 0
