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
tmpt > ostop , const multiset<T> &x) itfr
tmpt , class V> ostop , const map<T,V> &x) itfr
tmpt , class V> ostop , const pair<T,V> &p) { o << "(";o << p.first << ", " << p.second << ")"; return o;}
const int INF = int(1e9) + 5;
#define all(x) (x).begin(), (x).end()

struct Seg {
	vector<multiset<int>> t;
	vector<int> A;
	int n = 1;
	Seg(const vector<int> & a) {
		A = a;
		while(n < (int) a.size())
			n <<= 1;
		t.resize(2*n);
		build(a, 1, 0, n-1);
	}
	void build(const vector<int> &a, int x, int lx, int rx) {
		if(lx == rx) {
			if(lx < (int) a.size())
				t[x] = multiset<int> {a[lx]};
			return;
		}
		int mid = (lx + rx) / 2;
		build(a, 2*x, lx, mid);
		build(a, 2*x + 1, mid + 1, rx);
		t[x].insert(all(t[2*x]));
		t[x].insert(all(t[2*x+1]));
	}
	void update(int x, int lx, int rx, int i, int X) {
		t[x].erase(t[x].find(A[i]));
		t[x].insert(X);
		if(lx == rx) {
			A[i] = X;
			return;
		}
		int mid = (lx + rx) / 2;
		if(i <= mid) update(2*x, lx, mid, i, X);
		else update(2*x+1, mid+1, rx, i, X);
	}
	void update(int i, int X) {
		update(1, 0, n-1, i, X);
	}
	int query(int x, int lx, int rx, int l, int r, int X) {
		if(l > r) return INF;
		if(lx > r || rx < l) return INF;
		if(l <= lx && rx <= r) {
			auto pos = t[x].lower_bound(X);
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
		int m = n*10; //rng() % 10;
		while(m--) {
			int i = rng() % n, x = rng() % 999;
			seg.update(i, x);
			b[i] = x;
			//debug(i, x, seg.t, b);
		}
		int q = 100; //rng() % 10;
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

