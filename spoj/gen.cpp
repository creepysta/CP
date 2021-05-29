#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int ran(int a, int b, int x) {
	return a + x % (b-a);
}
int32_t main(int32_t argc, char * argv[]) {
	mt19937 rng(atoi(argv[1]));
	cout << 1 << "\n";
	int m = 1,
		n = 1000;
	int x = ran(m, n, rng());
	int y = ran(m, n, rng());
	cout << x << " " << y << "\n";
	return 0;
}
