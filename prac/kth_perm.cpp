/*
author: Creepysta
24-02-2021 19:52:29
*/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int MOD = int(1e9) + 7;
const int nax = int(1e6) + 5;
int fact[nax];
int inv[nax];

void brute() {
	int x, y, k;
	cin >> x >> y >> k;
	string path = string(x, 'H') + string(y, 'V');
	int i = 0;
	do {
		if(i == k)
			break;
		i++;
	} while(next_permutation(path.begin(), path.end()));
	cout << path << '\n';
}

int findIndex(int &k, int n) {
	if(n==1)
		return 0;
	n--;
	int n_partial_fact = n;
	while(n_partial_fact <= k && n > 1) {
		n_partial_fact *= (n-1);
		n--;
	}
	int fnum_idx = k / n_partial_fact;
	k %= n_partial_fact;
	return fnum_idx;
}

void solve() {
	int n, k;
	cin >> n >> k;
	string ans = "";
	set<int> s;
	for(int i = 1; i <= n; i++)
		s.insert(i);
	auto it = s.begin();
	k--;
	for(int i = 0; i < n; i++) {
		int idx = findIndex(k,n-i);
		advance(it, idx);
		ans += to_string(*it);
		s.erase(it);
		it = s.begin();
	}
	cout << ans << '\n';
	//return ans;
}

int modpow(int a, int b, int mod) {
	int result = 1;
	while(b) {
		if(b & 1) result = (result * a) % mod;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return result;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	memset(fact, 0, sizeof fact);
	memset(inv, 0, sizeof inv);
	fact[0] = inv[0] = 1;
	for(int i = 1; i < nax; i++) {
		fact[i] = (fact[i-1] * i) % MOD;
		inv[i] = modpow(fact[i],MOD-2, MOD);
	}

	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		//brute();
		solve();
	}
	return 0;
}
