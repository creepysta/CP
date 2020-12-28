/*
	author: Creepysta
	18-10-2020 22:38:51
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	srand(stoi(argv[1]));
	int n = rand() % 10, k = rand() % 10;
	cout << 1 << endl << n << ' ' << k << endl;
	for(int i = 0; i < n; i++)
		cout << rand() % 10 << ' ';
	cout << endl;
	return 0;
}

