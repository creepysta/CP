#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int mod = 1e9+7;

void solve() {
	ll n;
	cin >> n;
	ll ans = 0LL;
	// O(n * root(n))
	/*
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j*j <= i; j++) {
			if(i % j == 0) {
				ans = (ans + j) % mod;
				if(i / j != j) ans = (ans + i / j) %mod;
			}
		}
	}
	*/
	// linear not good
	/*
	for(int i = 1; i <= n; i++) {
		ans = (ans + ((n/i) * i) % mod) % mod;
	}
	*/
	// let's try root(n)
	auto sumtill= [&](ll x){
		x %= mod;
		ll sum = x*(x+1);
		sum %= mod;
		sum *= (mod+1)/2;
		sum %= mod;
		return sum;
	};
	for(ll i=1;i*i<n;i++){
		if(i == n/i){
			continue;
		}
		ans+= n/i * i;
		ans%=mod;
	}
	for(ll i=1;i*i<=n;i++){
		ans += (sumtill(n / i) - sumtill(n / (i + 1))) * i;
		ans%=mod;
	}
	cout << ans << '\n';	
	return;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll t=1;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}
