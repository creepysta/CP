#include <bits/stdc++.h>
using namespace std;

int main() {
	int k, r;
	cin >> k >> r;
	int i = 1;
	for(; (k*i - r) % 10 && (k*i) % 10; i++) {}
	cout << i;
	return 0;
}
