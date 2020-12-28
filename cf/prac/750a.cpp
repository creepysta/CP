#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int four = 4 * 60;
	int num = 0;
	four -= k;
	int i = 1;
	while(i <= n && i*5 <= four) {
		num ++;
		four -= (i++) * 5;
	}
	cout << num;
	return 0;
}
