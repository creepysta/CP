// works in online cpp compiler
// natively throws segmentation fault

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int range = 9;
	int ip[] = {1, 4, 1, 2, 7, 5, 2};
	int count[range+1];
	memset(count, 0, sizeof(count));
	int op[8];

	for(int i = 0; ip[i]; i++) {
		count[ip[i]]++;
	}

	for(int i = 1; i <= range; i++) {
		count[i] += count[i-1];
	}

	for(int i = 0; i <= range; i++)
		cout << count[i] << "\t";
	cout << endl;

	for(int i = 0; ip[i]; i++) {
		op[count[ip[i]]-1] = ip[i];
		count[ip[i]]--;
	}

	for(int i = 0; ip[i]; i++) {
		ip[i] = op[i];
	}

	for(int i = 0; ip[i]; i++) {
		cout << ip[i] << endl;
	}

	return 0;
}

