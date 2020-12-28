#include <bits/stdc++.h>
using namespace std;

struct pt {
    int x, y;
	pt() {}
    pt(int _x, int _y) : x(_x), y(_y) {}
    bool operator==(const pt &p) { return x == p.x && y == p.y; }
};

void operator<<(ostream &cout, const pt &p) {
	cout << p.x << ' ' << p.y << endl;
}

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}


int slope(const pt &p, const pt &q, const pt &r) {
	return (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
    //return slope(a, b, c) > 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
    //return slope(a, b, c) < 0;
}

vector<vector<pt>> hulls;

bool convex_hull(vector<pt>& a) {
	int n = a.size();
    sort(a.begin(), a.end(), &cmp);
    if(n <= 2) return false;
    if(n == 3 && slope(a[0], a[1], a[2]) == 0) return false;
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < n; i++) {
        if (i == n - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == n - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    //a.clear();
    vector<pt> hull;
	for (int i = 0; i < (int)up.size(); i++)
		hull.push_back(up[i]);
	for (int i = down.size() - 2; i > 0; i--)
		hull.push_back(down[i]);
	hulls.push_back(hull);
	a.erase( remove_if( a.begin(),a.end(),
	[&](auto x){return find(hull.begin(),hull.end(),x)!=hull.end();}), a.end() );
	return true;
}

int main() {
	int tt;
	cin >> tt;
	for(int t = 1; t <= tt; t++) {
		cout << "case #" << t << ":" << endl;
		int n; cin >> n;
		vector<pt> points(n);
		for(int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			points[i] = pt(x, y);
		}
		while(convex_hull(points));
		cout << "HuLLS\n";
		for(auto hh : hulls) {
			cout << "hulls\n";
			for(auto pp : hh)
				cout << pp;
		}
	}

	return 0;
}
