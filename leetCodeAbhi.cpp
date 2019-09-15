#include <bits/stdc++.h>
using namespace std;

int binSrch(vector<int> v, int k) {
	int l = 0;
	int u = (int) v.size() -1;
	int m = (l + u) / 2;
	while(l < u) {
		if(v[m] == k) {
			return m;
		} else if(k > v[m]) {
			l = m + 1;
		} else {
			u = m - 1;
		}
		m = (l + u) / 2;
	}
	return k < v[m] && m > 0 ? m - 1 : m;
}

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	vector<int> r(n);
	for(int i = 0; i < n ;i++) {
		cin >> p[i] >> r[i];
	}
	int q;
	cin >> q;
	while(q--) {
		int s, e;
		int mx = 0;
		cin >> s >> e;
		int it1 = binSrch(p, s), it2 = binSrch(p, e);
		//cout << it1 << it2 << '\n';
		for(int i = it1; i <= it2 ;i ++) {
			mx = max(mx, r[i]);
		}
		cout << mx << endl;
	}

	return 0;
}
