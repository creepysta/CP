/*
	author: Creepysta
	05-03-2021 10:35:35
*/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int MOD = int(1e9) + 7;
const int nax = int(1e9) + 5;

//struct pt {
	//int l, r;
	//pt(int _l=-1, int _r=-1) : l(_l), r(_r) {};
	//void read() {
		//cin >> l >> r;
	//}
	//bool isnull() const {
		//return l == -1 || r == -1 || r < l;
	//}
	//int len() const {
		//if (isnull())
			//return 0;
		//return r - l + 1;
	//}
//};

//bool ovr(pt a, pt b) {
	//if(a.l > b.l) 
		//swap(a,b);
	//if(a.r < b.l || a.l > b.r)
		//return false;
	//return true;
//}

//pt comm(const pt& a, const pt& b) {
	//pt p{max(a.l,b.l), min(a.r, b.r)};
	//return pt;
//}

//void solve() {
	//vector<pt> a(4);
	//for(int i = 0; i < 4; i++)
		//a[i].read;
	//vector<pt> ops(12,0);
	//for(int i = 0; i < 4; i++) {
		//int l = (i+1)%4, r = (i-1+4)%4;
		//pt rcom, lcom, rem; 
		//bool lovr = ovr(a[i],a[l]);
		//bool rovr = ovr(a[i],a[r]);
		//if(lovr) {
			//lcom = comm(a[i],a[l]);
			//ops[i+0] = lcom;
		//}
		//if(rovr) {
			//rcom = comm(a[i],a[r]);
			//ops[i+1] = rcom;
		//}
		//ops[i+2] = 
	//}
//}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	//cin >> t;
	//for(int tt = 1; tt <= t; tt++) {
		 //cout << "Case #" << tt << ": ";
		//solve();
	//}
	vector<vector<int>> a{{1,2,2,3},{1,2,3},{1},{3,2,1},{3,2,2,1}};
	for(int i = 0; i < (int) a.size(); i++) {
		if(a[i].size() == 1) 
			cout << 1 << endl << 1 << endl;
		else {
			bool ok = true;
			for(auto it = a[i].begin()+1; it != a[i].end(); it++) {
				if(*it <= *(it-1))
					ok = false;
			}
			cout << ok << endl;
			ok = true;
				for(auto it = a[i].rbegin()+1; it != a[i].rend(); it++) {
					if(*it <= *(it-1))
						ok = false;
				}
			cout << ok << endl;
		}
	}
	return 0;
}

