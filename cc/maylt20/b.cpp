#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF LLONG_MAX
#define MIN LLONG_MIN
#define MOD 1000000007
#define endl '\n'

//ll dp[10001][10001];
//ll dp[1000001];

vector<ll> a, b;

void solve() {
	ll n;
	cin >> n;
	ll ga = 0, gb = 0, ans = 0;
	a.clear(); a.resize(n);
	b.clear(); b.resize(n);
	for(ll &i : a) cin >> i;
	for(ll &i : b) cin >> i;
	for(ll i = 0; i < n; i++) {
	    if(a[i] != b[i]) {
	        ga+=a[i]; gb+=b[i];
	    }
	    if(ga == gb) {
	        if(a[i] == b[i]) {
	            ans += a[i];
	            ga = gb = 0;
	        }
	    }
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1,tt=1;
	cin >> t;
	while(tt <= t) {
// 		cout << "case #" << tt << ":\n";
		solve();
		tt++;
	}

	return 0;
}
