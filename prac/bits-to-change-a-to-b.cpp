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
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

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
		ll n, m;
		cin >> n >> m;
		bitset<32> a, b;
		a |= n; b |= m;
		cout << (a^b).count() << endl;
	}

	return 0;
}
