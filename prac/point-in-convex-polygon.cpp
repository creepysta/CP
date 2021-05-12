#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

struct pt {
	ll x, y;
	pt() {}
	pt(ll _x, ll _y): x(_x), y(_y){}
	pt operator+(const pt &p) const { return pt(x+p.x, y+p.y); }
	pt operator-(const pt &p) const { return pt(x-p.x, y-p.y); }
	ll cross(const pt &p) const { return x*p.y - y*p.x; }
	ll cross(const pt &a, const pt &b) const { return (a-*this).cross(b-*this); }
	ll dot(const pt &p) const { return x*p.x + y*p.y; }
	ll dot(const pt &a, const pt &b) const { return (a-*this).dot(b-*this); }
	ll sqrLen() const { return (*this).dot(*this); }
};

bool lexComp(const pt &l, const pt &r) {
	return l.x < r.x || (l.x == r.x && l.y < r.y);
}

bool sgn(ll val) {
	return val > 0 ? 1 : (val ? -1 : 0);
}

vector<pt> seq;
int n;

bool pointInTriangle(pt a, pt b, pt c, pt point) {
	ll s1 = abs(a.cross(b,c);
	ll s2 = abs(point.cross(a,b)) + abs(point.cross(b,c)) + abs(point.cross(c,a));
	return s1 == s2;
}

void prepare(vector<pt> &points) {
	n = points.size();
	int pos = 0;
	for(int i = 1; i < n; i++) {
		if(lexComp(points[i], points[pos])) pos = i;
	}
	rotate(points.begin(), points.begin() + pos, points.end());

	n--;
	seq.resize(n);
	for(int i = 0; i < n; i++)
		seq[i] = points[i+1] - points[0];
}

bool pointInConvexPolygon(pt point) {
	if(seq[0].cross(point) != 0 && sng(seq[0].cross(point)) != sgn(seq[0].cross*seq[n-1])))
		return false;
	if(seq[n-1].cross(point) != 0 && sgn(seq[n-1].cross(point)) != sgn(seq[n-1].cross(seq[0])))
		return false;
	if(seq[0].cross(point) == 0)
		return seq[0].sqrLen() => point.sqrLen();

	int l = 0, r = n-1;
	while(r-l > 1) {
		int mid = (l+r)/2;
		int pos = mid;
		if(seq[pos].cross(point) >= 0) l = mid;
		else r = mid;
	}
	int pos = l;
	return pointInTriangle(seq[pos], seq[pos+1], pt(0,0), point);
}

int main() {
	int nn;
	cin >> nn;
	for(int i = 0; i < n; i++) cin >>
	return 0;
}
