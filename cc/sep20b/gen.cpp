/*
	author: Creepysta
	18-09-2020 13:08:44
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(int argc, char *argv[]) {
	srand(stoi(argv[1]));
	ios_base::sync_with_stdio(false);
	int n = rand() % 8;
	n = 5;
	cout << 1 << '\n' << n << '\n';
	for(int i = 0; i < n; i++)
		cout << rand() % 6 << ' ';
	cout << endl;
	return 0;
}

