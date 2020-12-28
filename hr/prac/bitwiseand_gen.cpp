/*
	author: Creepysta
	01-12-2020 20:56:05
*/
#include <bits/stdc++.h>
using namespace std;

int random(int a, int b) {
	return a + rand() % (b - a + 1);
}

int main(int argc, char *argv[]) {
	srand(atoi(argv[1]));
	cout << 1 << endl;
	int n = random(2, 100);
	int k = random(2, n);
	cout << n << ' ' << k << endl;
	return 0;
}

