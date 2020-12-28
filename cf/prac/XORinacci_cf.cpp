#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	long long a, b, n;
	long long ans;

	cin >> t;
	while(t--) {
		cin >> a >> b >> n;
		long count = 2;
		
		switch (n%3) {
			case 0:
				cout << a << "\n";
				break;
			case 1:
				cout << b << "\n";
				break;
			default:
				cout << (a ^ b) << "\n";
				break;
		}
	}

	return 0;
}
