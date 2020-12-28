#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t=1;
	//cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[5];
		memset(a, 0, sizeof(a));
		for(int i = 0; i < n; i++) {
			int x;
			cin>>x;
			a[x]++;
		}
		//for(int i : a) cout << i << ' ';
		//cout << endl;
		int ans = 0;
		int ot = min(a[1], a[3]);
		ans += a[4] + ot + a[2] / 2;
		a[1] -= ot;a[3] -= ot;
		if(a[2]%2) {
			if(a[1]>0) a[1] -=2;
			ans++;
		}
		if(a[1] > 0) ans += ceil(a[1] /4.0);
		// shud b rite
		//if(a[3] > 0) ans += ceil(3*a[3] /4.0);
		// ffs idk
		if(a[3] > 0) ans += a[3];
		cout << ans << endl;
	}
	return 0;
}
