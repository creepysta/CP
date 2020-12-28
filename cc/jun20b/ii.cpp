#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct pt {
    int x, y;
	pt() {}
    pt(int _x, int _y) : x(_x), y(_y) {}
	bool operator==(const pt &p) const { return x==p.x && y==p.y; }
	pt operator+(const pt &p) const { return pt(x+p.x, y+p.y); }
	pt operator-(const pt &p) const { return pt(x-p.x, y-p.y); }
	int cross(const pt &p) const { return x*p.y - y*p.x; }
	int cross(const pt &a, const pt &b) const { return (a-*this).cross(b-*this); }
	int dot(const pt &p) const { return x*p.x + y*p.y; }
	int dot(const pt &a, const pt &b) const { return (a-*this).dot(b-*this); }
	int sqrLen() const { return (*this).dot(*this); }
};

void operator<<(ostream &cout, const pt &p) {
	cout << p.x << ' ' << p.y << endl;
}

bool cmp(const pt &a, const pt &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int slope(const pt &p, const pt &q, const pt &r) {
	//return (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
	return (q-p).cross(r-p);
}

int dist(const pt &p, const pt &q) {
	return (p.x - q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y);
}

vector<pt> points, hull, qq;
vector<vector<pt>> hulls;

bool build() {
	int n = points.size();
    if(n <= 2) return false;
	pt fp = points[0];
	int mp = 0;
	for(int i = 1; i < n; i++) {
		if(!cmp(fp, points[i])) {
			fp = points[i];
			mp = i;
		}
	}
	swap(points[0], points[mp]);
    sort(points.begin()+1, points.end(), [&](const pt &p, const pt &q) {
		int slp = slope(fp, p, q);
		if(slp == 0) {
			return dist(fp, p) > dist(fp,q);
		}
		return slp < 0;
	});
    if(n == 3 && slope(points[0], points[1], points[2]) == 0) return false;
    //vector<pt> hull;
    hull.clear();
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    hull.push_back(points[2]);
    for(int i = 3; i < n; i++) {
		while(slope(hull.end()[-2], hull.end()[-1], points[i]) > 0) {
		//while(hull.size() >= 2 && (hull.end()[-2]-hull.end()[-1]).cross(hull.end()[-2]- points[i]) < 0) {
			hull.pop_back();
		}
		hull.push_back(points[i]);
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
		ans &= (slope(poly[i], poly[(i+1)%n], p) < 0);
	}
	return ans;
}

void solve() {
	int n, q; cin >> n >> q;
	points.clear(); points.resize(n);
	//vector<pt> qq(q);
	qq.clear(); qq.resize(q);
	hulls.clear();
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		points[i] = pt(x, y);
	}
	for(int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		qq[i] = pt(x, y);
	}
	while(build());
	//cout << "HuLLS\n";
	//for(auto hh : hulls) {
		//cout << "hulls\n";
		//for(auto pp : hh)
			//cout << pp;
	//}
	for(auto pp : qq) {
		int hh = hulls.size();
		bool found = false;
		for(int i = hh-1; i >= 0; i--) {
			if(pip(hulls[i], pp)) {
				found = true;
				cout << i + 1 << endl;
				break;
			}
		}
		if(!found) cout << 0 << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int tt;
	cin >> tt;
	for(int t = 1; t <= tt; t++) {
		//cout << "case #" << t << ":" << endl;
		solve();
	}

	return 0;
}
