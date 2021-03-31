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

void solve() {
	int x, y, k;
	cin >> x >> y >> k;
	string path = string(x, 'H') + string(y, 'V');    
	int freq[26];
	memset(freq, 0, sizeof freq);
	for(char c : path)
		freq[c-'A']++;
	//get kth perm
	int sum = 1, n = path.length(), idx=0;
	char ans[26];
	k++;
	while (sum != k) {
		sum = 0;
		for(int i = 0; i < 26; i++) {
			if (freq[i] == 0)
				continue;     
			// fix char
			freq[i]--;
			int xsum = fact[n-idx-1];
			for(int j = 0; j < 26; j++)
				xsum /= fact[freq[j]];
			sum += xsum;
			if(sum >= k) {
				ans[idx++] = i + 'A';
				k -= (sum - xsum);
				break;
			}
			if (sum < k)
				freq[i] ++;
		}
	}
	for(int i = 25; idx < n && i >= 0; i--) {
		if(freq[i]) {
			ans[idx++] = i+'A';
			freq[i++]--;
		}
	}
	ans[idx] = '\0';
	cout << ans << '\n';
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
