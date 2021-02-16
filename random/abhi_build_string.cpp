#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int nax = int(1e6) + 5;
const int MOD = int(1e9) + 7;
int fact[nax], inv[nax];
int N;

int modpow(int a, int b, int c) {
	int result = 1;
	while(b) {
		if(b & 1) result = (result * a) % c;
		a = (a*a) % c;
		b>>=1;
	}
	return result;
}

void init() {
	memset(fact, 0, sizeof fact);
	memset(inv, 0, sizeof inv);
	fact[0] = 1, inv[0] = 1;
	for(int i = 1; i < nax; i++) {
		fact[i] = (fact[i-1] * i) % MOD;
		inv[i] = modpow(fact[i], MOD-2, MOD);
	}
}
string s = "";
int solve(int i, char c, int ans) {
	int val = 0;
	if(i == N) {
		cout << s << endl;
		s = "";
		return ans;
	}
	s += string(1, c);
	if(c == 'a') {
		val += solve(i+1, 'e', (ans+1) % MOD);
		val += solve(i+1, 'o', (ans+1) % MOD);
	}
	if(c == 'e') {
		val += solve(i+1, 'i', (ans+1) % MOD);
	}
	if(c == 'i') {
		for(char cc : {'a', 'e', 'o', 'u'})
			val += solve(i+1, cc, (ans+1) % MOD);
	}
	if(c == 'o' || c == 'u')
		val += solve(i+1, 'i', (ans+1) % MOD);
	return val;
}

int32_t main() {
	cin >> N;
	init();
	int ans = 0;
	ans = solve(0, 'a', 1);
	//for(char c : {'a', 'e', 'i', 'o', 'u'})
	//	ans += solve(0, c, 1);
	cout << ans << endl;
	return 0;
}


/*
 * a > e/o
 * e/o/u > i
 * i > a/e/o/u
 *
 *
 * a e i o u
 * a _ (e or o)
 * i can be last
 * e o u i
 * n = 7
 * a e/o i a e/o _ _ i
 * a e/o i e/o i _ _ i
 * 
 * 
 *
 *total = n P 5
 *
 *
 * a e i
 * a o i
 */
