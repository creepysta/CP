#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll dp[100000];
int main() {
	ll t = 1;
	cin >> t;
	while(t--) {
		memset(dp, 0LL, sizeof(dp));
		ll n;
		cin >> n;
		ll a[n];
		for(ll i = 0; i < n; i++) {
			cin >> a[i];
			cout << a[i] << ' ';
		}
		cout << '\n';
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            dp[i] = 1;
            for(int j = 0; j < i; j++) {
                if(a[i] >= a[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
		//cout << *max_element(dp, dp + n + 1) << '\n';
		for(int i = 0; i < n; i++)
			cout << dp[i] << ' ';
		cout << '\n';
	}

	return 0;
}
