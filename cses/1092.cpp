#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long int

void solve() {
	ll n;
	cin >> n;
	ll sum = (n*(n+1))/2;
	bool pos = floor(sum/2.0) == ceil (sum/2.0);
	if(pos) {
		cout << "YES\n";
		ll half = sum/2;
		vector<int> ls, rs;
		while(n) {
			if(half - n >= 0) {
				ls.push_back(n);
				half -= n;
			} else {
				rs.push_back(n);
			}
			n--;
		}
		cout << ls.size() << endl;
		for(int i : ls)
			cout << i << ' ';
		cout << endl << rs.size() << endl;
		for(int i : rs)
			cout << i << ' ';
		cout << endl;
	}
	else 
		cout << "NO\n";
	return;
}

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;
	// cin >> t;
	t = 1;
	while(t--) {
		solve();
	}
	return 0;
}

