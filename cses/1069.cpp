#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	string s;
	cin >> s;
	int c = 1, ans = -1;
	for(int i = 1; i < (int) s.length(); i++) {
		if(s[i-1] == s[i]) c++;
		else {
			ans = max(ans, c);
			c=1;
		}
	}
	ans = max(ans, c);
	cout << ans;
	return 0;
}
