#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF LLONG_MAX
#define MIN LLONG_MIN
#define MOD 1000000007
#define endl '\n'

//ll dp[10001][10001];
//ll dp[1000001];

vector<ll> a;

void solve() {
	ll n = 6;
	a.clear(); a.resize(n);
	for(ll &i: a) cin >> i;
	ll p = a[5];
    int sum = 0;
	for(int i = 0; i< 5; i++) {
	    sum += a[i]*p;
	}
	if(sum > 24*5) {
	    cout << "Yes\n";
	} else {
	    cout << "No\n";
	}
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
