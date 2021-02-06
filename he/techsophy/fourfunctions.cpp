/*
	author: Creepysta
	30-12-2020 17:33:44
*/
#include <bits/stdc++.h>
using namespace std;

const int nax = int(1e1) + 7;
int primes[nax];
int sum[nax];

void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < 10; i++) {
		cout << i << ": " << primes[i] << ' ' << sum[i] << endl;
	}
	cout << endl;
	cout << sum[n] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	memset(primes, 0, sizeof primes);
	memset(sum, 0, sizeof sum);
	for(int i = 2; i < nax; i++) {
		if(!primes[i]) {
			for(int j = i; j < nax; j += i) {
				primes[j] = primes[j-i] + 1;
			}
		}
	}
	sum[0] = primes[0];
	for(int i = 0; i < nax; i++) {
		sum[i] = sum[i-1] + primes[i];
	}
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

