#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long int
#define ld long double
#define ff first
#define ss second
#define pii pair<int,int>
#define pll pair<ll,ll>

const int nax = 1e9 + 5;
const int mod = 1e9 + 7;

ull power(ull a, ull b) {
	ll result = 1;
	while(b) {
		if(b&1) result = (result*a) % mod;
		a = (a*a) % mod;
		b >>= 1;
	}
	return result;
}

ull divide(ull a, ull b) {
	return (a%mod)*(power(b, mod-2) % mod);
}

ull gcd(ull x, ull y) {
	while(y) {
		ull t = x % y;
		x = y;
		y = t;
	}
	return x;
}

ull choose(ull n, ull k) {
	if(k > n) return 0ULL;
	ull r = 1ULL;
	for(ull d = 1; d <= k; d++, --n) {
		ull g = gcd(r, d);
		r = r/g;
		ull t = n / (d/g);
		r *= t;
	}
	return r;
}

void opt(ll n, const vector<ll> &a) {
	
}

void brute(ll n, const vector<ll> &a) {
	vector<int> ans(n, 0);
	for(ll mask = 1; mask < 1 << n; mask++) {
		unordered_map<int, int> tab;
		ll cm = 0, ci = -1;
		for(ll i = 0; i < n; i++) {
			if(mask & (1<<i)) {
				tab[a[i]]++;
				if(tab[a[i]] > cm) {
					cm = tab[a[i]];
					ci = i;
				}
			}
		}
		ans[a[ci]-1] = (ans[a[ci]-1] + 1) % mod;
	}
	for(int i : ans) cout << i << ' ';
	cout << endl;
}

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(ll &i : a) cin >> i;
	//cout << "input\n";
	//for(ll &i : a) cout << i << ' ';
	//cout << endl;
	sort(a.begin(), a.end());
	// brute
	brute(n, a);
	// optimise
	//opt(n, a);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}
