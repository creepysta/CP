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
// Input : [3, 10, 5, 25, 2, 8]
// Output : 28
// 11001 ^ 00101 = 25 ^ 5
// 2:  00010
// 3:  00011
// 5:  00101
// 8:  01000
// 10: 01010
// 25: 11001

int main() {
	//fastio;
	ll t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		vector<ll> a(n);
		ip(a, n);
		bitset<64> check;
		check = 1 << 64;

	}

	return 0;
}
