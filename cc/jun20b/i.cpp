#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

struct pt {
	ll x, y;
	pt() {}
	pt(ll _x, ll _y): x(_x), y(_y){}
	bool operator==(const pt &p) const { return x==p.x && y==p.y; }
	pt operator+(const pt &p) const { return pt(x+p.x, y+p.y); }
	pt operator-(const pt &p) const { return pt(x-p.x, y-p.y); }
	ll cross(const pt &p) const { return x*p.y - y*p.x; }
	ll cross(const pt &a, const pt &b) const { return (a-*this).cross(b-*this); }
	ll dot(const pt &p) const { return x*p.x + y*p.y; }
	ll dot(const pt &a, const pt &b) const { return (a-*this).dot(b-*this); }
	ll sqrLen() const { return (*this).dot(*this); }
};

void operator<<(ostream &cout, const pt &p) {
	cout << p.x << ' ' << p.y << endl;
}

vector<pt> points;
vector<vector<pt>> hulls;

bool cmp (const pt &p, const pt &q) {
	return p.x < q.x || (p.x == q.x && p.y < q.y);
}

//int slope(const pt &p, const pt &q, const pt &r) {
	////return (q-p).cross(r-p);
	//return (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
    ////return p.x*(q.y-r.y)+q.x*(r.y-p.y)+r.x*(p.y-q.y);
//}

//bool cw(const pt &p, const pt &q, const pt &r) {
	//return slope(p, q, r) > 0;
	////return slope(p, q, r) < 0;
//}

//bool ccw(const pt &p, const pt &q, const pt &r) {
	//return slope(p, q, r) < 0;
	////return slope(p, q, r) > 0;
//}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

bool buildHull() {
	int n = points.size();
	if(n <= 2) return false;
	sort(points.begin(), points.end(), &cmp);
	pt pl = points[0], pr = points.back();
	vector<pt> up, down;
	up.push_back(pl);
	down.push_back(pr);
	for(int i = 1; i < n; i++) {
		if(i == n-1 || cw(pl, points[i], pr)) {
			while(up.size() >= 2 && ccw(up.end()[-2], up.back(), points[i])) {
				up.pop_back();
			}
			up.push_back(points[i]);
		}
		if(i == n-1 || ccw(pl, points[i], pr)) {
			while(down.size() >= 2 && cw(down.end()[-2], down.back(), points[i])) {
				down.pop_back();
			}
			down.push_back(points[i]);
		}
	}
	vector<pt> hull;
	for(auto i : up) hull.push_back(i);
	for(int i = (int) down.size()-2; i > 0 ; i--) {
		hull.push_back(down[i]);
	}
	hulls.emplace_back(hull);
    points.erase( remove_if( points.begin(),points.end(),
	[&](auto x){return find(hull.begin(),hull.end(),x)!=hull.end();}), points.end() );
	return true;
}

bool pip(const vector<pt> &poly, const pt &p) {
	bool ans = true;
	int n = poly.size();
	for(int i = 0; i < n; i++) {
		ans &= ccw(poly[i], poly[(i+1)%n], p);
	}
	return ans;
}

void solve() {
	int n, qq;
	cin >> n >> qq;
	vector<pt> q(qq);
	hulls.clear();
	points.clear(); points.resize(n);
	for(int i = 0; i < n; i++) {
		int a,b; cin >> a >> b;
		points[i] = pt(a, b);
	}
	for(int i = 0; i < qq; i++) {
		int a,b; cin >> a >> b;
		q[i] = pt(a, b);
	}
	while(buildHull());
	for(auto hh : hulls) {
		cout << "hulls" << endl;
		for(pt p : hh) {
			cout << p;
		}
	}
	for(pt pp : q) {
		bool found = false;
		int hn = hulls.size();
		for(int i = hn-1; i >= 0; i--) {
			if(pip(hulls[i], pp)) {
				found = true;
				cout << i+1 << endl;
				break;
			}
		}
		if(!found) cout << 0 << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}
