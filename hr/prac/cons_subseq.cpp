/*
    author: Creepysta
    25-01-2021 15:16:09
*/
#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &i : a)
        cin >> i;
    vector<int> tab(k);
    tab[0] = 1;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum = (sum + a[i]) % k;
        tab[sum]++;
    }
	for(int i : tab)
		cout << i << ' ';
	cout << endl;
    int cnt = 0;
    for(int i = 0; i < k; i++)
        cnt += tab[i] * (tab[i] - 1);
    cnt /= 2;
    cout << cnt << '\n';
}

int32_t main() {
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


