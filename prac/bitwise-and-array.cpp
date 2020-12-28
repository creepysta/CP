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
//ll dp[1000001];

void ip(vector<ll> &a, ll n) {
	for(ll &i : a) cin >> i;
}

void ip1(vector<ll> &a, ll n) {
	for(ll i = 1; i <= n; i++) cin >> a[i];
}

void op(vector<ll> &a) {
	for(ll i : a) cout << i << ' ';
	cout << endl;
}

void op1(vector<ll> &a) {
	int n = a.size();
	for(ll i = 1; i <= n; i++) cout << a[i] << ' ';
	cout << endl;
}


int main() {
	//fastio;
	ll t;
	cin >> t;
	while(t--) {
		ll l, r;
		cin >> l >> r;
		ll ans;
		//Sol1:
		//		to simply do and from r as long as > l
		//ans = r;
		//while(ans > l) {
			//ans &= r-1;
			//r--;
		//}

		//Sol2:
		//		check using mask for closest 0 for a particular bit
		//ans = 0;
		//ll mask = 1;
		//for(ll i = 0; i < 64; i++) {
			//if (l & mask) {
				//ll clear_right = (mask << 1) - 1;
				//ll left = l & (~clear_right);
				//ll check_num = left + (mask << 1);
				//if (check_num < l || check_num > r)
					//ans |= 1 << i;
			//}
			//mask <<= 1;
		//}
		//cout << ans << endl;

		//Sol 3:
		// tricky and simple
		// 111
		// 101
		ll i = 0;
		while(l ^ r) {
			l >>= 1;
			r >>= 1;
			i+=1;
		}
		ans = l << i;
		cout << ans << endl;
	}

	return 0;
}
