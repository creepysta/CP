#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int nax = int(1e6) + 5;
int tab[nax];

void solve() {
    int n, big = INT_MIN;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tab[x]++;
        big = max(big, x);
    }
    int ans = 0;
    for(int i = 0; i <= big; i++) {
        ans += tab[i] * (tab[i]-1);
    }
    cout << ans << '\n';
}

int32_t main() {
    int T;
    cin >> T;
    while(T--) {
		memset(tab, 0, sizeof tab);
        solve();
    }
    return 0;
}
