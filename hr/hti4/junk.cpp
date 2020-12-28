#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define endl '\n'

//ll dp[10001][10001];
//ll dp[1000001];

//int dx[] = {-1, 0, 1, 0},
	//dy[] = {0, 1, 0, -1};
pair<ll, ll> dp[301][301];
pair<ll,ll> findPath(vector<vector<ll>> &a, ll i, ll j, ll n, ll m, pair<ll, ll> prev) {
	// is safe
	pair<ll,ll> t1, t2;
	if(i == n-1 && j == m-1) {
		//return dp[i][j];
		return make_pair(a[prev.first][prev.second], abs(a[prev.first][prev.second]-a[i][j]));
	}
	if(dp[i][j] !=
	if(i <0 || i > n || j <0 || j >m) {
		return make_pair(a[prev.first][prev.second], LLONG_MIN);
	}
	cout << a[prev.first][prev.second] << ' ' << a[i][j] << ' ' << i << ' ' << j << ' ' << abs(a[prev.first][prev.second] -a[i][j]) << endl;
	if(dp[i][j].second == -1) {
		t1 = findPath(a, i+1, j, n, m, make_pair(i, j));
		t2 = findPath(a, i, j+1, n, m, make_pair(i, j));
		//dp[i][j] = make_pair(a[prev.first][prev.second], max(t1.second, t2.second));
		//return dp[i][j];
	}
	//if(dp[i][j].second == -1) {
		//t2 = findPath(a, i, j+1, n, m, make_pair(i, j));
	//}
	dp[i][j] = make_pair(a[prev.first][prev.second], max(t1.second, t2.second));
	return dp[i][j];
	//else {
		//dp[i][j].second = max(dp[i][j].second, max(t1.second, t2.second));
		//return dp[i][j];
	//}
}

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> a(n, vector<ll>(m));
	for(ll i =0; i< n ;i++) {
		for(ll j = 0; j < m; j++) {
			cin >> a[i][j];
			dp[i][j].first = a[i][j];
		}
	}
	ll ans = findPath(a, 0, 0, n-1, m-1, make_pair(0,0)).second;
	cout << ans << endl;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1,tt=1;
	cin >> t;
	while(tt <= t) {
		for(int i =0; i <= 300; i++) {
			for(int j = 0; j <= 300; j++) {
				dp[i][j] = make_pair(-1,-1);
			}
		}
		//cout << "case #" << tt << ":\n";
		solve();
		tt++;
	}

	return 0;
}
