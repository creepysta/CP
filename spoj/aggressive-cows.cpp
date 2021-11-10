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

bool put(int dist) {
	int prev = a[0], placed = 1;
	for(int i = 1; i < n; i++) {
		if(a[i] - prev >= dist) {
			prev = a[i];
			placed ++;
		}
		if(placed == c)
			return 1;
	}
	return 0;
}

void solve() {
	cin >> n >> c;
	a = vector<int> (n);
	for(int & i : a)
		cin >> i;
	sort(a.begin(), a.end());
    debug(n, c);
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
    // below doesn't work since we need to find upper bound for a solution which places all cows
    // can be done by doing ans += d (where d = powers of 2) but then we require upper_bound queries on stalls array
    // which results in O(log*log)
    //int ans = INF;
    //for(int d = a[n-1]/2; d >= 1; d/=2) {
        //int last = 0, placed = 1;
        //vector<pair<int, int>> pos;
        //pos.emplace_back(last, a[last]);
        //bool ok = 0;
        //for(int i = 1; i < n; i++) {
            //if(a[i] - a[last] >= d) {
                //placed++;
                //ans = min(ans, a[i]-a[last]);
                //last = i;
                //pos.emplace_back(last, a[last]);
            //}
            //if(placed == c)
                //ok = 1;
        //}
        //debug(d, pos, ans, placed);
        //if(ok) {
            //cout << ans << '\n';
            //return;
        //}
    //}
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
