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
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

//ll dp[10001][10001];
//ll dp[100001];

int main() {
	fastio;
	ll t, tt=1;
	cin >> t;
	while(tt <=t) {
		ll n, x;
		cin >> n;
		bitset<50000> a;
		for(ll i = 0; i < n; i++) {
			cin >> x;
			if(x) a[i] = 1;
		}
		cout << "case #" << tt <<endl;
		//for(ll i = 0; i < n; i++) cout << a[i] << ' ';
		//cout << endl;
		ll cnt = 0, tlen = 0, len=0, ans = 0;
		unordered_map<ll, ll> table;
		for(ll i=0; i < n; i++) {
			cnt = 0;
			len = tlen =0;
			for(ll j = i; j < n; j++) {
				if(a[j]) cnt ++;
				else cnt --;
				tlen++;
				if(!cnt) {
					len = tlen;
				}
				// 012345
				//
				if(abs(cnt) > n-1-i && len < ans) break;
				//cout << a[j] << ' ' << cnt << ' ' << tlen << endl;
			}
			ans = max(ans,len);
		}
		cout << ans << endl;
		tt++;
	}

	return 0;
}
