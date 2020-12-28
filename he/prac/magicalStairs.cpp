/*
 * https://www.hackerearth.com/challenges/competitive/kotlin-a-thon-a-jetbrains-contest/algorithm/the-magical-stairs-bed325e7/
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n+1, 0);
	for(ll i=1; i<=n; i++) cin >> a[i];
	ll cSteps, iSteps, maxSteps = LLONG_MIN, cs, cur =1;
	ll ans = 0;
	//bool wind = false, nmax = false;
	cSteps = a[1];
	cs = 1;
	iSteps = cSteps;
	for(ll i=2; i <= n;i++) {
		//wind = nmax = false;
		if(i <= cSteps) {
			if(i+a[i] > cSteps && cs <= iSteps) {
				cSteps = i+a[i];
				//wind = true;
				if(cs+1 <= iSteps) {
					cs++;
				} else{
					//i = cs;
					//continue;
				}
			}
			if(i+a[i] <= n && a[i+a[i]] >= n) {
				ans += 1;
				break;
			}
			else if(i+a[i] <= n && a[i+a[i]] > maxSteps) {
				maxSteps = a[i+a[i]];
				//nmax = true;
				cur = cs;
			}
		} else {
			cout << "else\n";
			i = cur;
			ans ++;
			iSteps = i + a[i];
			cSteps = iSteps;
			cs =  i;
			i += 1;
		}
		cout << cSteps << " " << iSteps <<  " " << maxSteps <<  " " << cur <<  " " << cs <<  " " << i << endl;
	}
	cout << ans << endl;
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--) {
		solve();
	}
}
