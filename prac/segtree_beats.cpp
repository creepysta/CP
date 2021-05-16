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
#define itfr { if(!x.empty()) o << "[";for(auto e : x) o << e << ", "; o<<"\b\b]"; return o;}
void err(istream_iterator<string> it) { cerr << "\b\b ]\n";}
tmpt , class... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << ": " << a << ", "; err(++it, args...); }
tmpt > ostop , const vector<T> &x) itfr
tmpt > ostop , const set<T> &x) itfr
tmpt > ostop , const multiset<T> &x) itfr
tmpt , class V> ostop , const map<T,V> &x) itfr
tmpt , class V> ostop , const pair<T,V> &p) { o << "(";o << p.first << ", " << p.second << ")"; return o;}

//static const int INF = numeric_limits<int>::max();

const int INF = int(1e9) + 5;

struct SegBeats {
	struct Node {
		int maxVal, maxVal2, cntMax, sum, minVal;
		Node() : maxVal(-INF), maxVal2(-INF), cntMax(0), sum(0), minVal(INF) {}
		Node(int x) : maxVal(x), maxVal2(-INF), cntMax(1), sum(x), minVal(x) {}
		void merge(const Node& L, const Node& R) {
			if (L.maxVal == R.maxVal) {
				maxVal = L.maxVal;
				maxVal2 = max(L.maxVal2, R.maxVal2);
				cntMax = L.cntMax + R.cntMax;
			} else {
				maxVal = max(L.maxVal, R.maxVal);
				maxVal2 = max(min(L.maxVal, R.maxVal), max(L.maxVal2, R.maxVal2));
				cntMax = (maxVal == L.maxVal) ? L.cntMax : R.cntMax;
			}
			sum = L.sum + R.sum;
			minVal = min(L.minVal, R.minVal);
		}
		bool isBreak(int value) const {
			return value >= maxVal;
		}
		bool isTag(int value) const {
			return value > maxVal2;
		}
		friend ostream& operator<<(ostream& o, const Node &n) {
			o << "[" << n.maxVal << ' ' <<
				n.maxVal2 << ' ' << n.cntMax << ' ' <<
				n.sum <<
				//' ' << n.minVal <<
				"]";
			return o;
		}
	};
	int n;
	vector<Node> t;
	SegBeats(const vector<int> &A) : n(1) {
		//while(n < (int) A.size())
			//n <<= 1;
		n = A.size();
		t.resize(4*n);
		build(1, 0, n-1, A);
	}
	void build(int x, int lx, int rx, const vector<int> &a) {
		if(lx == rx) {
			if(lx < (int) a.size())
				t[x] = Node(a[lx]);
			return;
		}
		int mid = (lx + rx) / 2;
		build(2*x, lx, mid, a);
		build(2*x+1, mid+1, rx, a);
		t[x].merge(t[2*x], t[2*x+1]);
	}
	void updateNode(int x, int val) {
		t[x].minVal = min(t[x].minVal, val);
		t[x].sum -= t[x].cntMax * (t[x].maxVal - val);
		t[x].maxVal = val;
	}
	void push(int x) {
		if(t[x].maxVal < t[2*x].maxVal)
			updateNode(2*x, t[x].maxVal);
		if(t[x].maxVal < t[2*x+1].maxVal)
			updateNode(2*x+1, t[x].maxVal);
	}
	void update(int x, int lx, int rx, int l, int r, int X) {
		if(l > r || rx < l || t[x].isBreak(X))
			return;
		push(x);
		if(l <= lx && rx <= r && t[x].isTag(X)) {
			updateNode(x, X);
			return;
		}
		int mid = (lx + rx) / 2;
		update(2*x, lx, mid, l, r, X);
		update(2*x+1, mid + 1, rx, l, r, X);
		t[x].merge(t[2*x], t[2*x+1]);
	}
	void update(int l, int r, int X) {
		update(1, 0, n-1, l, r, X);
	}
	pair<int,int> queryMin(int x, int lx, int rx, int l, int r) {
		if(lx > r|| rx < l)
			return make_pair(INF, -INF);
		if(l <= lx && rx <= r)
			return make_pair(t[x].minVal, t[x].maxVal);
		push(x);
		int mid = (lx + rx) / 2;
		auto left = queryMin(2*x, lx, mid, l, r);
		auto right = queryMin(2*x+1, mid + 1, rx, l, r);
		return make_pair(min(left.first, right.first), max(left.second,
					right.second));
	}
	int querySum(int x, int lx, int rx, int l, int r) {
		if(lx > r|| rx < l)
			return 0;
		if(l <= lx && rx <= r)
			return t[x].sum;
		push(x);
		int mid = (lx + rx) / 2;
		auto left = querySum(2*x, lx, mid, l, r);
		auto right = querySum(2*x+1, mid + 1, rx, l, r);
		return left + right;
	}
	pair<int,int> queryMin(int l, int r) {
		return queryMin(1, 0, n-1, l, r);
	}
	int querySum(int l, int r) {
		return querySum(1, 0, n-1, l, r);
	}
};

int32_t main() {
	for(int tt=1; tt <= 10000; tt++) {
		mt19937 rng(tt);
		int n = 1 + rng() % 10;
		vector<int> a(n), b;
		for(int i = 0; i < n; i++) {
			a[i] = 10 + rng() % 20;
		}
		SegBeats seg(a);
		b = a;
		debug(seg.t, b);
		for(int l = 0; l < n; l++) {
			for(int r = n-1; r >= 0; r--) {
				int X = rng() % 20;
				seg.update(l, r, X);
				for(int i = l; i <= r; i++)
					b[i] = max(b[i], X);
			}
		}
		for(int l = 0; l < n; l++) {
			for(int r = n-1; r >= 0; r--) {
				for(int rep = 0; rep < 2; rep++) {
					if(rep) {
						auto  got = seg.querySum(l, r);
						int should = 0;
						for(int i = l; i <= r; i++)
							should += b[i];
						debug(l,r, should, got);
						assert(should == got);
					} else {
						auto got = seg.queryMin(l, r);
						int small = INF, big = -INF;
						for(int i = l; i <= r; i++)
							small = min(small, b[i]), big = max(big, b[i]);
						auto should = make_pair(small, big);
						debug(l, r, should, got);
						assert(should == got);
					}
				}
			}
		}
	}
	return 0;
}
