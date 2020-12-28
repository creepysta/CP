#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll solve() {
	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	ll ans = 0;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	sort(a, a+n, greater<int> ());
	sort(b, b+m);
	//for(int i = 0, j = 0; i < m; i++, j++) {
		//ans += a[j];
		//b[i]--;
		////cout << a[j] << ' ' << b[i] << endl;
	//}
	/*
	 *	doesn't work because i consider element already given prevly
	 */
	//int c = 0;
	//for(int i = 0; i < m; i++) {
		////cerr << "if: " << b[i] << ' ' << a[c] << endl;
		//ans += a[c+b[i]];
		//c += b[i]+1;
	//}

	for(int i = 0, j = 0; i < m; i++, j++) {
		ans += a[j];
		b[i]--;
		if(!b[i]) ans += a[j];
	}
	int c = m;
	for(int i = 0; i < m; i++) {
		if(b[i]) {
			ans += a[c+b[i]-1];
			c += b[i];
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin >>t;
	while(t--) {
		ll ans = solve();
		cout << ans << endl;
	}
	return 0;
}
