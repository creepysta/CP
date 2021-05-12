/*
	author: Creepysta
	26-01-2021 17:15:12
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

bool intersect(P p1, P p2, P p3, P p4) {
	/*
	 *	handles parallel cases
	 	p1 o------------o p2
		p3 o------------o p4
	 * */
	if((p2-p1) * (p4-p3) == 0) {
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
	/*
	 * 2nd rep of the below loop is required for cases as this
		p1 o-----------o p2
			p3	o
				|
				|
				|
			p4	o

	 * else the 1st iteration would be enough if it was strictly to the left or right of a particular line segment
	 	p2 o				p3  o
			\					|
			 \					|
			  \					|
			   \				|
			p1  o			p4	o
	 * */
	for(int rep = 0; rep < 2; rep ++) {
		int s1 = p1.cross(p2, p3);
		int s2 = p1.cross(p2, p4);
		if((s1 < 0 && s2 < 0) || (s1 > 0 && s2 > 0))
			return false;
		swap(p1, p3);
		swap(p2, p4);
	}
	return true;
}

void solve() {
	P a, b, x, y;
	a.read(), b.read(), x.read(), y.read();
	int got = intersect(a, b, x, y);
	if(got)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}


