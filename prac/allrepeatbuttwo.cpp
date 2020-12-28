//#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
//#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx")
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
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

void tobin(ll num, ll bits) {
	while(bits--) {
		cout << ((num>>bits) & 1ll);
	}
	cout << endl;
}

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(ll &i : a) cin >> i;
	ll ans = 0;
	for(ll i : a) {
		ans ^=i;
	}
	// 121425 ans = 100 ^ 101 = 001
	// setbit = ans & ~(ans -1) = 001
	// 121325
	// ans = 011 ^ 101 = 110
	// setbit = ans & ~(ans -1) = 010
	//cout << "xor of all \n";
	//tobin(ans, 4);
	ll n1=0, n2=0;
	ll setbit = ans & ~(ans -1);
	//cout << "setbit \n";
	//tobin(setbit, 4);
	for(ll num : a) {
		//cout << num << ' ';
		//tobin(num&setbit,4);
		if(num & setbit) {
			n1 ^= num;
		} else {
			n2 ^= num;
		}
		//cout << "n1: " << n1 << " n2: " << n2 << endl;
	}
	cout << n1 << ' ' << n2 << endl;
}

int main() {
	fastio;
	ll t,tt=1;
	cin >> t;
	while(tt <= t) {
		cout << "case #" << tt << ":\n";
		solve();
		tt++;
	}

	return 0;
}
