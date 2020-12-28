#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve() {
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n);
	for(ll i = 0; i < n ; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	//for(ll i : a) cout << i << ' ';
	//cout << " x: " << x << endl;
	ll i = -1;
	ll ans = 0, cnt = 0;
	while(i+1<n){
		//finding the right position for x i.e a[i] <= x < a[i+1].
		if(x>=a[i+1]){
			i++;
			continue;
		}
		// If v[i]*2>x we deliver to country i.
		if(i>=0&&(a[i]*2)>x){
			x=a[i]*2;
			cnt++;
			ans++;
			continue;
		}
		// If next element is the last one we keep on delivering it.
		if((i+1)==(n-1)){
			while(x<a[n-1]){
				x=x*2;
				ans++;
			}
			cnt++;
			ans++;
			break;
		}
		//To double x we deliver last element
		if((i+1)!=(n-1)&&x<=a[n-1]/2){
			x*=2;
			ans++;
			continue;
		}
		//We just take (remaining countries+1) days more in this condition.
		if((i+1)!=(n-1)&&x>a[n-1]/2){
			ans++;
			break;
		}
	}
	ans+=(n-cnt);
	cout << ans << endl;
}

int main() {
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}
