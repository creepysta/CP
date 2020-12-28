#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF LLONG_MAX
#define MIN LLONG_MIN
#define MOD 1000000007
#define endl '\n'

//ll dp[10001][10001];
//ll dp[1000001];

void solve() {
	ll n;
	cin >> n;
	int a[n], b[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	sort(a, a+n);
	sort(b, b+n);
	ll i = 0, j = 0;
	bool fcheck = 1, scheck = 1;
	while(i+1 < n && j < n) {
		if(a[i] <= b[j] && a[i+1] >= b[j]) {
			i++; j++;
		} else {
			fcheck = 0;
			break;
		}
		if(fcheck && a[i] > b[j]) fcheck = 0;
	}
	if(!fcheck) {
		i = j = 0;
		while(i < n && j + 1< n) {
			if(b[j] <= a[i] && b[j+1] >= a[i]) {
				i++; j++;
			} else {
				scheck = 0;
				break;
			}
		}
		if(scheck && a[i] < b[j]) scheck = 0;
	}
	if(fcheck | scheck) {
		cout << "YES" << endl;
	} else cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t,tt=1;
	cin >> t;
	while(tt <= t) {
		//cout << "case #" << tt << ":\n";
		solve();
		tt++;
	}

	return 0;
}
