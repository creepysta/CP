#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	while(n--) {
		int a, b, c;
		cin >> a >> b >> c;
		if(a^b) {
			if(c) ans ++;
		} else {
			if(a || b) ans ++;
		}
	}
	cout << ans;
	return 0;
}
