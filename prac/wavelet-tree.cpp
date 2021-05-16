/*
	author: Creepysta
	14-05-2021 21:50:35
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

const int MAX = 1e6+5;

struct wavelet_tree {
	int lo, hi;
	wavelet_tree *l, *r;
	vector<int> b;
	int n;
	wavelet_tree(int *from, int *to, int x, int y) {
		lo = x, hi = y;
		if(lo == hi || from >= to) return;
		int mid = (lo + hi) / 2;
		auto f = [mid](int x) { return x <= mid; };
		b.reserve(to-from+1);
		b.push_back(0);
		for(auto it = from; it != to; it++)
			b.push_back(b.back() + f(*it));
		auto pivot = stable_partition(from, to, f);
		l = new wavelet_tree(from, pivot, lo, mid);
		r = new wavelet_tree(pivot, to, mid + 1, hi);
	}
	// kth smallest element in [l, r]
	int kth(int l, int r, int k) {
		if(l > r) return 0;
		if(lo == hi) return lo;
		int inLeft = b[r] - b[l-1];
		int lb = b[l-1]; // total nos in first (l-1) nos that go in left
		int rb = b[r]; // total nos in first (r) nos that go in left
		if(k <= inLeft) return this->l->kth(lb+1, rb, k);
		return this->r->kth(l-lb, r-rb, k-inLeft);
	}
	//count of nos in [l, r] Less than or equal to k
	int LTE(int l, int r, int k) {
		if(l > r or k < lo) return 0;
		if(hi <= k) return r - l + 1;
		int lb = b[l-1], rb = b[r];
		return this->l->LTE(lb+1, rb, k) + this->r->LTE(l-lb, r-rb, k);
	}

	//count of nos in [l, r] equal to k
	int count(int l, int r, int k) {
		if(l > r or k < lo or k > hi) return 0;
		if(lo == hi) return r - l + 1;
		int lb = b[l-1], rb = b[r], mid = (lo+hi)/2;
		if(k <= mid) return this->l->count(lb+1, rb, k);
		return this->r->count(l-lb, r-rb, k);
	}
	~wavelet_tree(){
		delete l;
		delete r;
		l = r = nullptr;
	}
};

int32_t main() {
	int i,n,k,j,q,l,r;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	wavelet_tree T(a, a+n, 1, MAX);
	cin >> q;
	while(q--){
		int x;
		cin >> x;
		cin >> l >> r >> k;
		if(x == 0){
			//kth smallest
			cout << "Kth smallest: ";
			cout << T.kth(l, r, k) << endl;
		}
		if(x == 1){
			//less than or equal to K
			cout << "LTE: ";
			cout << T.LTE(l, r, k) << endl;
		}
		if(x == 2){
			//count occurence of K in [l, r]
			cout << "Occurence of K: ";
			cout << T.count(l, r, k) << endl;
		}
	}
	return 0;
}

