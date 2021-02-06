#include <bits/stdc++.h>
using namespace std;

int random(int a, int b) {
	return rand() % b + a;
}

int main(int argc, char *argv[]) {
	srand(stoi(argv[1]));
	cout << 1 << endl;
	int big = 10;
	int n = random(1, big);
	cout << n << endl;
	for(int i = 0; i < n; i++) {
		int x = random(1,big);
		cout << x << ' ';
	}
	cout << endl;
	return 0;
}
