#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, sum = 0, count = 0;
	while (1) {
		cin >> x;
		if(x >=0) { 
			sum += x;
			count += 1;
		}
		else break;
	}
	sum /= count;
	cout << sum;
	return 0;
}
