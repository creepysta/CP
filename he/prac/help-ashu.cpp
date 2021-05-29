/*
	author: Creepysta
	16-05-2021 22:08:11
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9) + 7;
#define int int64_t
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


struct node {
	int odd, even, val;
	node() : odd(0), even(0), val(0) {}
	node(int v) : odd(v % 2), even(v % 2 == 0), val(v) {}
	node(int o, int e, int v) : odd(o), even(e), val(v) {}
	node operator+ (node o) const {
		return {odd+o.odd, even+o.even, -1};
	}
	friend ostream& operator << (ostream& o, node n) {
		debug(n.odd, n.even, n.val);
		return o;
	}
};
struct seg {
	vector<node> t;
	int n;
	seg(const vector<int> &a) : n(1) {
		while(n < (int) a.size()) {
			n <<= 1;
		}
		t.resize(2*n);
		build(1, 0, n-1, a);
	}
	void build(int x, int lx, int rx, const vector<int> &a) {
		if(lx == rx) {
			if(lx < (int) a.size())
				t[x] = node(a[lx]);
			return;
		}
		int mid = (lx + rx) / 2;
		build(2*x, lx, mid, a);
		build(2*x+1, mid+1, rx, a);
		node left = t[2*x], right = t[2*x+1];
		t[x] = left + right;
	}
	void update(int x, int lx, int rx, int i, int X) {
		if(lx == rx) {
			t[x] = node(X);
			return;
		}
		int mid = (lx + rx) / 2;
		if(i <= mid)
			update(2*x, lx, mid, i, X);
		else
			update(2*x+1, mid + 1, rx, i, X);
		node left = t[2*x], right = t[2*x+1];
		t[x] = left + right;
	}
	void update(int i, int X) {
		return update(1, 0, n-1, i, X);
	}
	node query(int x, int lx, int rx, int l, int r) {
		if(lx > r || rx < l) return node();
		if(l <= lx && rx <= r) return t[x];
		int mid = (lx + rx) / 2;
		node left = query(2*x, lx, mid, l, r);
		node right = query(2*x+1, mid + 1, rx, l, r);
		return left + right;
	}
	node query(int l, int r) {
		return query(1, 0, n-1, l, r);
	}
};
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int &i : a)
		cin >> i;
	seg S(a);
	debug(S.t);
	int q;
	cin >> q;
	while(q--) {
		int choice;
		cin >> choice;
		if(choice) {
			int l, r;
			cin >> l >> r;
			l--, r--;
			node got = S.query(l, r);
			debug(choice, l, r, got);
			if(choice == 1)
				cout << got.even << "\n";
			else
				cout << got.odd << "\n";
		}
		else {
			int i, X;
			cin >> i >> X;
			i--;
			debug(i, X);
			S.update(i, X);
		}
	}
}

int32_t main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	int t = 1;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

