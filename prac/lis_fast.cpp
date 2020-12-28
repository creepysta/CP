#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), d(n+1, INF);
	for(int &i : a) {
		cin >> i;
		cout << i << ' ';
	}
	cout << '\n';
	vector<pair<int, int>> dp(n+1);
	for(int i = 0; i < n + 1; i++)
		dp[i] = make_pair(INF, -1);
	dp[0] = make_pair(-INF, -1);
	d[0] = -INF;
	for(int i = 0; i < n; i++) {
		int l = 0, h = n, j = -1;
		while(l <= h) {
			int mid = (l + h) / 2;
			if(d[mid] <= a[i]) {
				j = mid;
				l = mid + 1;
			} else
				h = mid - 1;
		}
		//printf("%d %d %d %d %d %d\n", i, a[i], j, d[j], j+1, d[j+1]);
		if(d[j] <= a[i] && a[i] < d[j+1]) {
			d[j+1] = a[i];
			dp[j+1] = make_pair(a[i], i);
		}
		//int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
		//if(d[j-1] < a[i] && d[j] > a[i]) {
		//	d[j] = a[i];
		//	dp[j] = make_pair(a[i], i);
		//}
	}
	//for(int i = 0; i < n+1; i++)
	//	printf("[%d,%d] ", dp[i].first, dp[i].second);
	//cout << endl;
	vector<int> pos;
	for(int i = 0; i < n+1; i++) {
		if(dp[i].second != -1)
			pos.push_back(dp[i].second);
	}
	if(pos.back() != n-1)
		pos.push_back(n-1);
	vector<int> ans(n);
	int k = 0, lis = 1;
	for(int p : pos) {
		for(;k <= p; k++) {
			ans[k] = lis;
		}
		lis++;
	}
	for(int i : ans)
		cout << i << ' ';
	cout << '\n';
}

int main() {
	int T;
	cin >> T;
	for(int tt = 1; tt <= T; tt++)
		solve();
	return 0;
}
