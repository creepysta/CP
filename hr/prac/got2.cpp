/*
	author: Creepysta
	03-03-2021 09:24:39
*/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int MOD = int(1e9) + 7;
const int nax = int(1e5) + 5;
int fact[nax], inv[nax];

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	vector<int> f(26);
	for(char c : s)
		f[c-'a']++;
	int ans = 1, rem = 0, ways = 0, odd = 0;
	for(int i = 0; i < 26; i++)
		if(f[i] % 2)
			odd++;
	assert(odd <= 1);
	auto nCr = [&](int N, int R) {
		int den = (inv[N-R] * inv[R]) % MOD;
		return (fact[N] * den) % MOD;
	};
	n /= 2;
	for(int i = 0; i < 26; i++) {
		if(f[i] == 0)
			continue;
		rem = f[i] == 1 ? f[i] : f[i]/2;
		ways = n;
		n -= rem;
		int N = max(ways, rem), R = min(ways, rem);
		int choices = nCr(N, R);
		ans = (ans * choices) % MOD;
	}
	cout << ans << '\n';
}

int modpow(int a, int b, int c=MOD) {
	int result = 1;
	while(b) {
		if(b & 1) result = (result * a) % c;
		a = (a*a) % c;
		b >>= 1;
	}
	return result;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	fact[0] = inv[0] = 1;
	for(int i = 1; i < nax; i++) {
		fact[i] = (fact[i-1] * i) % MOD;
		inv[i] = modpow(fact[i], MOD-2);
	}
	int t = 1;
#ifdef LOCAL
	cin >> t;
#endif
	for(int tt = 1; tt <= t; tt++) {
#ifdef LOCAL
		cout << "Case #" << tt << ":\n";
#endif
		solve();
	}
	return 0;
}

