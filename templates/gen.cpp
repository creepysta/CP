#include <bits/stdc++.h>
using namespace std;

int main(int argc, char * argv[]) {
	mt19937 rng(atoi(argv[1]));
	cout << 1 << "\n";
	int x = rng() % 30;
	int y = rng() % 30;
	cout << x << " " << y << "\n";
	return 0;
}
