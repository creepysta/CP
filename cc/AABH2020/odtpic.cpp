/*
https://www.codechef.com/AABH2020/problems/ODTPIC
*/

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

void input(vector<ll> &a, ll n) {
	for(ll &i : a) cin >> i;
}

void input1(vector<ll> &a, ll n) {
	for(ll i = 1; i <= n; i++) cin >> a[i];
}

void out(vector<ll> &a) {
	for(ll i : a) cout << i << ' ';
	cout << endl;
}

void out1(vector<ll> &a) {
	int n = a.size();
	for(ll i = 1; i <= n; i++) cout << a[i] << ' ';
	cout << endl;
}


int main() {
	//fastio;
	ll t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		//vector<ll> a(n);
		//input(a, n);
		//input1(a, n);
	}

	return 0;
}
