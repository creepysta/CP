#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		string s;
		cin >> s;
		int n = s.length();
		if(s.length() > 10) cout << s[0] << n -2 << s[n-1] << endl;
		else cout << s << endl;
	}
	return 0;
}
