#include <bits/stdc++.h>
using namespace std;

int main() {

	long c, i;
	cin >> c;
	for(i = 1; c > 1+i+i*i; i++) {
		double y = (c - 1 - i - i * i) / (double(i) * 2);
		// if(y - int(y) == 0) {
		if(!((c-1-i-i*i)%(2*i))) {
			cout << i << " " << y << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	
	return 0;
}
