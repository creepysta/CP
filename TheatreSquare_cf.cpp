#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int m, n, a;
	cin >> m >> n >> a;
	
	cout << (long long) ceil(m / (double)a) * (long long) ceil(n / (double)a) << "\n";
	
	return 0;
}
