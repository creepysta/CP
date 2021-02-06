#include <bits/stdc++.h>
using namespace std;

int random(int a, int b) {
	return rand() % b + a;
}

int main(int argc, char *argv[]) {
	srand(atoi(argv[1]));
	cout << 1 << endl;
	//cout << random(1, 100);
	cout << atoi(argv[1]);
	return 0;
}
