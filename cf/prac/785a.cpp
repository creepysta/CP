/*
	author) Creepysta
	13-11-2020 19)43)09
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	uint32_t ans = 0;
	while(n--) {
		string s;
		cin >> s;
		if(s == "Icosahedron")
			ans += 20;
		else if(s == "Cube")
			ans += 6;
		else if(s == "Octahedron")
			ans += 8;
		else if(s == "Tetrahedron")
			ans += 4;
		else if(s == "Dodecahedron")
			ans += 12;
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ") ";
		solve();
	}
	return 0;
}

