#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n; cin >> n;
	int a[n];
	int me=1e9+5, ma =0;
	int ms=0,ml = 0;
	for(int i=0; i < n; i++) {
		cin >> a[i];
		if(a[i] > ma) ma = a[i], ml = i;
		if(a[i] <= me) me = a[i], ms = i;
	}
	int ans = 0;
	cerr << ms << ' ' << ml << endl;
	ans = n-1 - ms + ml;
	if(ms < ml)
		ans-=1;
	cout << ans;
	return 0;
}
