#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF LLONG_MAX
#define MIN LLONG_MIN
#define MOD 1000000007
#define endl '\n'

//ll dp[10001][10001];
//ll dp[1000001];

ll score(vector<ll> &a, ll x) {
	ll s = 0;
	for(ll i : a) {
		if (i <= x) s ++;
	}
	return s;
}

// 4 2 3 1 4
// 4 4 3 1 2

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(ll &i : a) cin >> i;
	ll l = 1, h = n -1;
	while(l < h) {
		ll mid = l + (h-l) /2;
		if(score(a, mid) <= mid) l = mid + 1;
		else h = mid;
	}
	cout << l << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t,tt=1;
	cin >> t;
	while(tt <= t) {
		cout << "case #" << tt << ":\n";
		solve();
		tt++;
	}

	return 0;
}
