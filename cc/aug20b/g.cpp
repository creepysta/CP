#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define pii pair<int,int>
#define ff first
#define ss second

void solve() {
	int n, c, k;
	cin >> n >> c >> k;
	vector<pii> lines[c];
	vector<int> V(c);
	for(int i = 0; i < n; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		lines[C-1].push_back({A, B});
	}
	for(int i = 0; i < c; i++) {
		cin >> V[i];
		sort(lines[i].begin(), lines[i].end(), [&](const pii &p, const pii &q) {
			return p.ff < q.ff;
		});
	}

}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}
