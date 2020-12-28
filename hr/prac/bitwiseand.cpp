/*
	author: Creepysta
	01-12-2020 20:14:59
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e9) + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    bool got = !(n & 1);
    for(int i = 0; got && i < 30; i++) {
        if(n & (1 << i))
            got = false;
        n ^= (1 << i);
    }
    int ans = n & (n - 1);
    if(ans >= k)
        ans = k-1;
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

