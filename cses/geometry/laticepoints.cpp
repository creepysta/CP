/*
	author: Creepysta
	27-01-2021 00:22:27
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
/*
 * Pick's Theorem
 * area = interior - boundary / 2 - 1;
 * interior = area - boundary / 2 + 1;
 *
 */
void solve() {
	int n;
	cin >> n;
	vector<P> poly(n);
	for(int i = 0; i < n; i++)
		poly[i].read();
	int boundary = 0, area = 0;
	for(int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		P diff = poly[j] - poly[i];
		int g = gcd(abs(diff.x), abs(diff.y));
		boundary += g;
	}
	for(int i = 0; i < n; i++)
		area += poly[i] * poly[(i+1)%n];
	area = abs(area); // 2 * area
	int interior = (area - boundary + 2) / 2;
	cout << interior << ' ' << boundary << '\n';
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

