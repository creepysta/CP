#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	srand(stoi(argv[1]));
	cout << 1 << endl;
	int n = 1 + rand() % 10;
	cout << n << endl;
	for(int i = 0; i < n; i++) {
		int num = 1 + rand() % 100;
		cout << num << ' ';
	}
	cout << endl;
}

