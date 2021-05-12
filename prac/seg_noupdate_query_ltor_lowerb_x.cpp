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
#define itfr { if(!x.empty()) o << "[";for(auto e : x) o << e << ", "; o<<"\b\b]"; return o;}
void err(istream_iterator<string> it) { cerr << "\b\b ]\n";}
tmpt , class... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << ": " << a << ", "; err(++it, args...); }
tmpt > ostop , const vector<T> &x) itfr
tmpt > ostop , const set<T> &x) itfr
tmpt , class V> ostop , const map<T,V> &x) itfr
tmpt , class V> ostop , const pair<T,V> &p) { o << "(";o << p.first << ", " << p.second << ")"; return o;}
const int INF = int(1e9) + 5;

struct Seg {
	vector<vector<int>> t;
	int n = 1;
	Seg(const vector<int> & a) {
		while(n < (int) a.size())
			n <<= 1;
		t.resize(2*n);
		build(a, 1, 0, n-1);
	}
	void build(const vector<int> &a, int x, int lx, int rx) {
		if(lx == rx) {
			if(lx < (int) a.size())
				t[x] = vector<int> {a[lx]};
			return;
		}
		int mid = (lx + rx) / 2;
		build(a, 2*x, lx, mid);
		build(a, 2*x + 1, mid + 1, rx);
		merge(t[2*x].begin(), t[2*x].end(), t[2*x+1].begin(), t[2*x+1].end(),
				back_inserter(t[x]));
	}
	void update(int x, int lx, int rx, int l, int r, int X) {
	}
	void update(int l, int r, int X) {
		update(1, 0, n-1, l, r, X);
	}
	int query(int x, int lx, int rx, int l, int r, int X) {
		if(l > r) return INF;
		if(lx > r || rx < l) return INF;
		if(l <= lx && rx <= r) {
			auto pos = lower_bound(t[x].begin(), t[x].end(), X);
			if(pos != t[x].end())
				return *pos;
			return INF;
		}
		int mid = (lx + rx) / 2;
		int left = query(2*x, lx, mid, l, r, X);
		int right = query(2*x+1, mid+1, rx, l, r, X);
		return min(left, right);
	}
	int query(int l, int r, int X) {
		return query(1, 0, n-1, l, r, X);
	}
};


int main() {
	for(int tt=1; tt <= 10000; tt++) {
		mt19937 rng(tt);
		int n = 1 + rng() % 10;
		vector<int> a(n), b;
		for(int i = 0; i < n; i++) {
			a[i] = 10 + rng() % 20;
		}
		Seg seg(a);
		b = a;
		debug(seg.t, b);
		//int m = n*10; //rng() % 10;
		//while(m--) {
			//int l = rng() % n, r = l + rng() % (n - l), x = rng() % 20;
			//seg.update(l, r, x);
			//for(int i = l; i <= r; i++) {
				//b[i] += x;
			//}
			//debug(l, r, x, seg.t, b);
		//}
		int q = n; //rng() % 10;
		while(q--) {
			int l = rng() % n, r = l + rng() % (n - l), x = rng() % *max_element(b.begin(), b.end());
			int got = seg.query(l, r, x);
			int shld = INF;
			vector<int> now(b.begin() + l, b.begin() + r + 1);
			sort(now.begin(), now.end());
			auto should = lower_bound(now.begin(), now.end(), x);
			if(should != now.end())
				shld = *should;
			debug(l,r,x, shld, got);
			assert(shld == got);
		}
	}
	return 0;
}
