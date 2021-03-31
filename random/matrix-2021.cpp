/*
	author: Creepysta
	03-03-2021 22:07:40
*/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int MOD = int(1e9) + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	stack<int> s;
	int area = 0, top = 0, area_top = 0, i = 0;
	while(i < n) {
		top = s.top();
		if(s.empty() || a[top] <= a[i])
			s.push(i++);
		else {
			s.pop();
			area_top = a[top] * (s.empty() ? i : i - s.top() - 1);
			area = max(area, area_top);
		}
	}
	while(!s.empty()) {
		top = s.top();
		s.pop();
		area_top = a[top] * (s.empty() ? i : i - s.top() - 1);
		area = max(area, area_top);
	}
	cout << area << '\n';
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

