/*
author: Creepysta
24-02-2021 19:52:29
*/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int MOD = int(1e9) + 7;
const int nax = 21; // int(1e6) + 5;
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
	vector<int> freq{x, y};
	//get kth perm
	int sum = 0, n = path.length(), m = 2, idx=0;
	char ans[n+1];
	k++;
	while(sum != k) {
		sum = 0;
		for(int Y = 0; Y < 2; Y++) {
			if(freq[Y] == 0)
				continue;
			freq[Y]--;
			int now = fact[n-idx-1];
			for(int j = 0; j < m; j++)
				now /= fact[freq[j]];
			sum += now;
			if(sum >= k) {
				ans[idx++] = Y == 0 ? 'H' : 'V';
				k -= (sum - now);
				break;
			}
			if (sum < k) {
				freq[Y]++;
			}
		}
	}
	for(int Y = 1; idx < n && Y >= 0; Y--) {
		if(freq[Y]) {
			ans[idx++] = Y == 0 ? 'H' : 'V';
			freq[Y++]--;
		}
	}
	ans[n] = '\n';
	cout << ans << '\n';
}

/*
f(s) = s!/(a!b!...z!)
if sum > k
assign s = s without ith char for which cal was done
else
assign n = n - f(S without ith char)
try next letter.
*/

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
		fact[i] = (fact[i-1] * i);// % MOD;
		inv[i] = modpow(fact[i],MOD-2, MOD);
	}

	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		//brute();
		solve();
	}
	return 0;
}


