#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF LLONG_MAX
#define MIN LLONG_MIN
#define MOD 1000000007
#define endl '\n'

void solve() {
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;
	vector<int> indices[26];
	vector<int> curr;
	vector<vector<int>> ans;
	for(ll i=0; i < n; i++) indices[s2[i]-'a'].emplace_back(i);
	bool vis[n+1];
	memset(vis, 0, sizeof(vis));
	for(int i = 25; i >= 0; i--) {
		if(indices[i].empty()) continue;
		curr.clear();
		for(ll j =0; j < n; j++) {
			if(!vis[j] && (s1[j] - 'a') >= i) {
				curr.emplace_back(j);
			}
		}
		bool ok = 1;
		for(int &pos : indices[i]) {
			vis[pos] = 1;
			if((s1[pos]-'a') != i) {
				ok = 0;
			}
		}
		if(ok) continue;
		// update
		char c = 'z';
		for(int &pos : curr)
			c = min(c, s1[pos]);
		for(int &pos : curr)
			s1[pos] = c;
		ans.emplace_back(curr);
	}
	if(s1 != s2) {
		cout << - 1<< endl;
		return;
	}
	cout << ans.size() << endl;
	for(vector<int> &vec : ans) {
		cout << vec.size() << ' ';
		for(int elem : vec) {
			cout << elem << ' ';
		}
		cout << endl;
	}

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
