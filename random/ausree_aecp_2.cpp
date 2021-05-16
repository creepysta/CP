/*
	author: Creepysta
	14-05-2021 16:00:07
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9) + 7;
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

/*
 * given binary sequence and window size k. and window [l, r]
 * minimise number of steps to make all 1 between l and r
 *
 * */

void solve(vector<int> vec, int k, int l, int r) {
	int n = vec.size();
	vector<int> a, b;
	a = b = vec;
	int start = 0, end = 0;
	// start = end always
	// greedy works
	for(int i = l; i <= r; i++) {
		if(a[i]) continue;
		int m = 0;
		start ++;
		while(m < k) {
			if(i+m < n) a[i + m] = 1;
				m++;
		}
		i += k-1;
	}
	for(int i = r; i >= l; i--) {
		if(b[i]) continue;
		int m = 0;
		end++;
		while(m < k) {
			if(i-m >= 0) b[i - m] = 1;
			m++;
		}
		i -= k-1;
	}
	vector<int> ans_s(a.begin() + l, a.begin() + r+1), ans_r(b.begin() + l,
			b.begin() + r+1);
	if(start > 0 || end > 0) {
		debug(vec, l, r, k, start, end);
	}
	for(int i : ans_s)
		assert(i == 1);
	for(int i : ans_r)
		assert(i == 1);
	assert(start == end);
}

int32_t main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	int t = 10000;
	for(int tt = 1; tt <= t; tt++) {
		mt19937 rng(tt);
		int n = 6;//1 + rng() % 10;
		n = rng() % 10;
		vector<int> a(n);
		int prob = rng() % 60;
		for(int i = 0; i < n; i++) {
			int choice = rng() % 100;
			if(choice <= prob) a[i] = 1;
		}
		for(int l = 0; l < n; l++) {
			for(int r = l; r < n; r++) {
				for(int k = 1; k <= r-l+1; k++) {
					solve(a, k, l, r);
				}
			}
		}
	}
	return 0;
}

