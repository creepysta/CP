/*
	author: Creepysta
23-04-2021 01:39:35
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9) + 7;
//#define int int64_t
#ifdef LOCAL
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << "debug: [ "; err(_it, args); }
#else
#define debug(args...) 0;
#endif
#define tmpt template < class T
#define ostop ostream& operator<<(ostream& o
#define itfr { if(x.empty()) return o; o << "[";for(auto e : x) o << e << ", "; o<<"\b\b]"; return o;}
void err(istream_iterator<string> it) { cerr << "\b\b ]\n";}
tmpt , class... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << ": " << a << ", "; err(++it, args...); }
tmpt > ostop , const vector<T> &x) itfr
tmpt > ostop , const set<T> &x) itfr
tmpt , class V> ostop , const map<T,V> &x) itfr
tmpt , class V> ostop , const pair<T,V> &p) { o << "(";o << p.first << ", " << p.second << ")"; return o;}

#define ll int64_t
ll sq(int x) {
	return x * x;
}
ll dist (const vector<int>& p, const vector<int>& q) {
	return sq(p[0] - q[0]) + sq(p[1] - q[1]);
}
vector<int> brute(const vector<vector<int>>& pts, const vector<vector<int>>& qq) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	vector<int> ans;
	ans.reserve(510);
	for(auto q : qq) {
		ll radius = (ll) q[2] * q[2];
		int cnt = 0;
		for(auto p : pts) {
			ll d = dist(p, vector<int> {q[0], q[1]});
			if(radius >= d)
				cnt++;
		}
		ans.push_back(cnt);
	}
	return ans;
}

vector<int> solve(vector<vector<int>>& pts, const vector<vector<int>>& qq) {
	//debug(pts, qq);
	vector<int> ans;
	sort(pts.begin(), pts.end(), [&](const auto& p, const auto& q) {return
			make_pair(p[0], p[1]) < make_pair(q[0], q[1]); });
	int n = pts.size();
	auto f = [&] (int x, bool lf, const function<bool(int, int)> cmp) {
		int l = 0, h = n-1, idx = -1;
		while(l <= h) {
			int mid = (h + l) / 2;
			//debug(l, h, mid, lf);
			if(cmp(pts[mid][0], x)) {
				idx = mid;
				if(lf) h = mid - 1;
				else l = mid + 1;
			} else {
				if(lf) l = mid + 1;
				else h = mid - 1;
			}
		}
		return idx;
	};
	for(auto q : qq) {
		ll rad = q[2] * q[2];
		int cnt = 0;
		int l = f(q[0] - q[2], 1, [&](int x, int y){return x>=y;});
		int r = f(q[0] + q[2], 0, [&](int x, int y){return x<=y;});
		l = l == -1 ? 0 : l;
		r = r == -1 ? n-1 : r;
		for(int j = l; j <= r; j++) {
			if(dist(pts[j], vector<int> {q[0], q[1]}) <= rad)
				cnt ++;
		}
		ans.push_back(cnt);
	}
	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1;
	for(int tt = 1; tt <= t; tt++) {
		//cout << "Case #" << tt << ": ";
		vector<vector<vector<int>>> q =  { {{2,3,1},{4,3,1},{1,1,2}},
			{{1,2,2},{2,2,2},{4,3,2},{4,3,3}} };
		vector<vector<vector<int>>> v = { {{1,3},{3,3},{5,3},{2,2}},
			{{1,1},{2,2},{3,3},{4,4},{5,5}} };
		for(int i = 0; i < (int) q.size(); i++) {
			auto ans = solve(v[i], q[i]);
			auto op = brute(v[i], q[i]);
			debug(ans, op);
			assert(ans == op);
		}
	}
	return 0;
}

