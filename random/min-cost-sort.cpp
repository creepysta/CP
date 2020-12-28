#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF LLONG_MAX
#define MIN LLONG_MIN
#define MOD 1000000007
#define endl '\n'

void solve() {
	ll n;
	cin >> n;
	int a[n];
	set<int> s;
	for(int &i : a) cin >> i, s.insert(i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1,tt=1;
	cin >> t;
	while(tt <= t) {
		cout << "case #" << tt << ":\n";
		solve();
		tt++;
	}

	return 0;
}

