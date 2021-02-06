/*
	author: Creepysta
	26-01-2021 22:58:46
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

void solve() {
	int n;
	cin >> n;
	vector<P> points(n);
	for(int i = 0; i < n; i++)
		points[i].read();
	int area = 0;
	for(int i = 0; i < n; i++) {
		area += points[i] * points[(i+1) % n];
	}
	area = abs(area); // calculates 2 * area;
	cout << area << '\n';
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

