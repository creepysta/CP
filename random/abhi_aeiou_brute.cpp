#include <bits/stdc++.h>
#define int int64_t
using namespace std;

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
const int nax = int(1e6) + 5;
const int MOD = int(1e9) + 7;

int N;

int solve(int i, char c) {
	int val = 0;
	if(i == N)
		return 1;
	if(c == 'a') {
		val = (val + solve(i+1, 'e')) % MOD
		val = (val + solve(i+1, 'o')) % MOD
	}
	if(c == 'i') {
		for(char cc : {'a', 'e', 'o', 'u'})
			val = (val + solve(i+1, cc)) % MOD
	}
	if(c == 'e' || c == 'o' || c == 'u')
		val = (val + solve(i+1, 'i')) % MOD
	return val;
}

int32_t main() {
	cin >> N;
	init();
	int ans = 0;
	auto t1 = std::chrono::high_resolution_clock::now();
	for(char c : {'a', 'e', 'i', 'o', 'u'})
		ans += solve(1, c);
	auto t2 = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::duration<double>>( t2 - t1 ).count();
	//auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

	//std::cout << duration << " secs\n";
	cout << ans << endl;
	return 0;
}


