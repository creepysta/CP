#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define ff first
#define ss second
#define endl '\n'

const ll MOD = 1e9 + 7;
const ll nax = 1e9 + 1;

void solve() {
	ll a, b;
	cin >> a >> b;
	vector<bool> isPrime(b-a+1, true);
	for(ll i = 2; i <= sqrt(b); i++)
		for(ll j = max(i*i, (a+i-1)/(i*i)); j <= b; j += i)
			isPrime[j-a] = false;
	if(a == 1)
		isPrime[0] = false;
	for(ll i = a; i <= b; i++)
		if(isPrime[i-a])
			cout << i << endl;
	cout << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}

