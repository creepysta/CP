/*
	author: Creepysta
	27-01-2021 09:44:20
*/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

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

int sq(int x) {
	return x * x;
}

int distance(const P &p1, const P &p2) {
	return sq(p1.x - p2.x) + sq(p1.y - p2.y);
}

int smallest_distance (const vector<P> &points) {
	int n = points.size();
	if(n <= 1)
		return INT64_MAX / 2;
	vector<P> left(points.begin(), points.begin() + n/2);
	vector<P> right(points.begin() + n/2, points.end());
	int d1 = smallest_distance(left);
	int d2 = smallest_distance(right);
	int d = min(d1, d2);
	vector<P> stripe;
	int middle_x = left.back().x;
	for(P p : left) {
		if(sq(middle_x - p.x) < d) //(p.x > middle_x - d)
			stripe.push_back(p);
	}
	for(P p: right) {
		if (sq(middle_x - p.x) < d) //(p.x < middle_x + d)
			stripe.push_back(p);
	}
	sort(stripe.begin(), stripe.end(), [&] (const P &p1, const P &p2) {
			return p1.y < p2.y;
			});
	for(int i = 0; i < (int) stripe.size(); i++) {
		for(int j=i+1; j<(int) stripe.size() && sq(stripe[j].y - stripe[i].y)<d; j++) {
			d = min(d, distance(stripe[i], stripe[j]));
		}
	}
	return d;
}



void solve() {
	int n;
	cin >> n;
	vector<P> points(n);
	for(int i = 0; i < n; i++)
		points[i].read();
	sort(points.begin(), points.end(), [&] (const P &p1, const P &p2) {
			return p1.x < p2.x;
			});
	if(n == 2) {
		cout << distance(points[0], points[1]) << '\n';
		return;
	}
	int ans = smallest_distance(points);
	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

