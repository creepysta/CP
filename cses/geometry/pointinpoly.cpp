/*
	author: Creepysta
	23-01-2021 11:21:59
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int MOD = int(1e9) + 7;

struct P {
	int x, y;
	P() : x(0), y(0) {}
	P(int _x, int _y) : x(_x) , y(_y) {}
	void read() {
		cin >> x >> y;
	}
	P operator -(const P &p) const {
		return P{p.x - x, p.y - y};
	}
	int operator *(const P &p) const {
		return x * p.y - y * p.x;
	}
	int cross (const P& p1, const P& p2) const {
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

bool colli(P p, P a, P b) {
	if(p.cross(a, b) != 0)
		return false;
	return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) && 
		min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}


bool intersect(P p1, P p2, P p3, P p4) {
	if((p2-p1)*(p4-p3) == 0) {
		if(p1.cross(p2, p3) != 0) {
			return false;
		}
		for(int rep = 0; rep < 2; rep++) {
			if(max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)) {
				return false;
			}
			swap(p1, p3);
			swap(p2, p4);
		}
		return true;
	}
	for(int rep = 0; rep < 2; rep++) {
		int s1 = p1.cross(p2, p3);
		int s2 = p1.cross(p2, p4);
		if((s1 < 0 && s2 < 0) || (s1 > 0 && s2 > 0)) {
			return false;
		}
		swap(p1, p3);
		swap(p2, p4);
	}
	return true;
}


void solve() {
	int n, m;
	cin >> n >> m;
	vector<P> points(n);	
	for(int i = 0; i < n; i++) {
		points[i].read();
	}
	//reverse(points.begin(), points.end());
	while(m--) {
		P p;
		p.read();
		int count = 0;
		P big = P(p.x+1, int(1e9) + int(3e8));
		bool inside = true, on = false;
		for(int i = 0; i < n; i++) {
			//int slope = points[i].cross(points[(i+1)%n], p);
			//if(slope == 0)
			if(colli(p, points[i], points[(i+1)%n]))
				on = true;
			if(intersect(p, big, points[i], points[(i+1)%n]))
				count++;
		}
		if(on)
			cout << "BOUNDARY\n";
		else if(count % 2)
			cout << "INSIDE\n";
		else
			cout << "OUTSIDE\n";
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
#ifdef LOCAL
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ":\n";
		solve();
	}
#else
	solve();
#endif
	return 0;
}

