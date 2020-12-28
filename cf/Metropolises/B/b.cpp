#include <bits/stdc++.h>
using namespace std;

int main() {
	int b, g, n;
	cin >> b >> g >> n;
	int c = 0;
	for(int i = 0; i <= n;i ++) {
		if(i <= b && (n-i) <=g) {
			c++;
		}
	}
	cout << c << endl;
	
	return 0;
}
