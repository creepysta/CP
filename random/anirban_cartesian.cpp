/*
	author: Creepysta
	14-02-2021 09:53:35
*/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int MOD = int(1e9) + 7;
vector<pair<int, int>> x, y;

int pos(const pair<int, int> &p, bool xy, bool u=false) {
	int k = xy == false ? p.first : p.second;
	if(u)
		++k;
	int l = 0, h = x.size() - 1;
	int ans = -1;
	while(l <= h) {
		int m = l + (h-l)/2;
		int e = xy == false ? x[m].first : y[m].second;
		if(e >= k) {
			ans = m;
			h = m - 1;
		} else
			l = m + 1;
	}
	return ans;
}

bool search(const pair<int, int> &p, bool xy, bool u=false) {
	int l = pos(p, xy), h = pos(p, xy, true) - 1;
	//cout << l << ' ' << h << '\n';
	int k = xy == false ? p.first : p.second;
	k = u ? k+1 : k-1;
	int ans = -1;
	while(l <= h) {
		int m = l + (h - l) / 2;
		int e = xy == false ? x[m].second : y[m].first;
		if(e >= k) {
			ans = m;
			h = m-1;
		} else
			l = m + 1;
	}
	if(ans == -1)
		return false;//ans != -1;//false;
	return xy == false ? x[ans] != p : y[ans] != p;
}

ostream& operator<<(ostream &out, pair<int, int> v) {
	out << v.first << ' ' << v.second;
	return out;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	x = y = a;
	sort(x.begin(), x.end());
	sort(y.begin(), y.end(), [&](const auto & p1, const auto & p2) {
			return make_pair(p1.second, p1.first) < make_pair(p2.second, p2.first);
		});
	//cout << "X:\n";
	//for(auto e : x)
	//	cout << e << endl;
	//cout << "Y:\n";
	//for(auto e : y)
	//	cout << e << endl;
	int ans = 0;
	//a = vector<pair<int, int>> {{1,1},{1,2}};
	//n = a.size();
	for(int i = 0; i < n; i++) {
		//cout << "left\n";
		bool left = search(a[i], true, false);
		//cout << "right\n";
		bool right = search(a[i], true, true); 
		//cout << "up\n";
		bool up = search(a[i], false, true);
		//cout << "down\n";
		bool down = search(a[i], false, false);
		if(left && right && up && down) {
			//cout << "got: " << a[i] << '\n';
			ans++;
		}
	}
	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ":\n";
		solve();
	}
	return 0;
}

