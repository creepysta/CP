#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	cin >> n;
	if(n==1) {
		cout << 1;
		return 0;
	}
	else if(n==2 || n==3) {
		cout << "NO SOLUTION";
		return 0;
	}
	for(int i = 2; i <= n; i+=2) {
		cout << i << ' ';
	}
	for(int i = 1; i <= n; i+=2) {
		cout << i << ' ';
	}
	return 0;
}
