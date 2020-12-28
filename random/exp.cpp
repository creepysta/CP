#include <bits/stdc++.h>
using namespace std;

const int inf = 1e6+1;
bool primes[inf];
int exps[inf];

int main() {
	int n;
	cin >> n;
	memset(primes, true, sizeof(primes));
	memset(exps, -1, sizeof(exps));
	int ans = 0;
	// find primes
	for(int i = 2; i*i <= n; i++) {
		if(primes[i]) {
			ans ++;
			exps[i] = 1;
			for(int j = i*i; j <=n; j+=i) {
				primes[j] = false;
			}
		}
	}
	// build exp sum;
	for(int i = 2; i < n; i++) {
		if(!primes[i]) {
			exps[curr / i]
		}
	}
	cout << ans;
	return 0;
}
