#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx")
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

void solve() {
	ll n, s;
	cin >> n >> s;
	vector<ll> a(n);
	ll cnt = 0;
	for(ll &i : a) cin >> i;
	ll i=0;
	while(i<n && !a[i]) i++;
	for(; i < n; i++) {
		ll j=i;
		ll sum=0;
		while((j < n && sum != s) && (sum+=a[j])) j++;
		if(sum == s) cnt+=1;
		while(j < n && a[j] == 0 &&(cnt++)) j++;
		cout << cnt << endl;
		//i = j;
	}
	cout << cnt << endl;
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
