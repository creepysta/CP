#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct P {
	int x, y;
	P() : x(0), y(0) {}
	P(int _x, int _y) : x(_x) , y(_y) {}
	void read() {
		cin >> x >> y;
	}
	P operator -(const P &p) const {
		return P{x - p.x, y - p.y};
	}
	int operator *(const P &p) const {
		return x * p.y - y * p.x;
	}
	int triangle (const P& p1, const P& p2) const {
		return (p1-*this) * (p2-*this);
	}
	bool operator <(const P &a) const {
		return make_pair(x, y) < make_pair(a.x, a.y);
	}
	friend ostream& operator <<(ostream& out, const P &p) {
		out << p.x << ' ' << p.y;
		return out;
	}
};

int n, m;
vector<P> points;
vector<vector<P>> hulls;

void init() {
	points.clear();
	points.resize(n);
	hulls.clear();
}

void compute() {
	vector<P> hull;
	vector<P> temp (points.begin(), points.end());
	// first take top half
	// only after considering the next point check the most recent last 3
	// points to decide whether i-1th point should stay or go from hull
	for(int rep = 0; rep < 2; rep++) {
		const int S = hull.size();
		for(P C: temp) {
			while((int) hull.size() - S >= 2) {
				P A = hull.end()[-2];
				P B = hull.end()[-1];
				if(A.triangle(B, C) <= 0) {
					break;
				}
				hull.pop_back();
			}
			hull.push_back(C);
		}
		hull.pop_back(); // remove the last point since it will be included in
						// the bottom tree
		reverse(temp.begin(), temp.end());
	}
	hulls.push_back(hull);
}

void solve() {
	cin >> n;
	//cin >> m;
	init();
	for(int i = 0; i < n; i++) {
		points[i].read();
	}
	sort(points.begin(), points.end());
	compute();
	cout << hulls[0].size() << '\n';
	for(auto hh : hulls) {
		for(auto h : hh) {
			cout << h << '\n';
		}
		cout << '\n';
	}
}

int32_t main() {
	int T = 1;
	//cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}
