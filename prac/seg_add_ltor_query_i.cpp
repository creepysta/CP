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

struct Seg {
	vector<int> t;
	int n;
	Seg(const vector<int> & a) : n(1) {
		while(n < (int) a.size())
			n <<= 1;
		t.resize(2*n);
		build(a, 1, 0, n-1);
	}
	void build(const vector<int> &a, int x, int lx, int rx) {
		if(lx == rx) {
			if(lx < (int) a.size())
				t[x] = a[lx];
			return;
		}
		int mid = (lx + rx) / 2;
		build(a, 2*x, lx, mid);
		build(a, 2*x + 1, mid + 1, rx);
		t[x] = 0;
	}
	void update(int x, int lx, int rx, int l, int r, int X) {
		if(l > r) return;
		if(lx > r || rx < l) return;
		if(l <= lx && rx <= r) {
			t[x] += X;
			return;
		}
		int mid = (lx + rx) / 2;
		update(2*x, lx, mid, l, r, X);
		update(2*x+1, mid + 1, rx, l, r, X);
	}
	void update(int l, int r, int X) {
		update(1, 0, n-1, l, r, X);
	}
	// can be tail recursive using a int &ans, where query(ans + t[x]) gets called
	int query(int x, int lx, int rx, int i) {
		if(lx == rx) return t[x];
		int mid = (lx + rx) / 2;
		if(i <= mid) return t[x] + query(2*x, lx, mid, i);
		else return t[x] + query(2*x + 1, mid + 1, rx, i);
	}
	int query(int i) {
		return query(1, 0, n-1, i);
	}
};

int main() {
	for(int tt=1; tt <= 100000; tt++) {
		mt19937 rng(tt);
		int n = 1 + rng() % 10;
		vector<int> a(n), b;
		for(int i = 0; i < n; i++) {
			a[i] = 10 + rng() % 20;
		}
		Seg seg(a);
		b = a;
		debug(seg.t, b);
		for(int i = 0; i < n; i++) {
			for(int j = n-1; j>= i; j--) {
				int l = i, r = j, x = rng() % 20;
				//debug(l, r, x);
				seg.update(l, r, x);
				for(int idx = l; idx <= r; idx++) {
					b[idx] += x;
				}
			}
		}
		for(int i = 0; i < n; i++) {
			int x = i;
			int got = seg.query(x);
			debug(x, b[x], got);
			assert(b[x] == got);
		}
	}
	return 0;
}
