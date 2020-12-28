#include <bits/stdc++.h>
using namespace std;

void toInt(const char * s, int &x) {
	sscanf(s,"%d", &x);
}

int main() {
	string s = "123";
	int x = 0;
	toInt(s.c_str(), x);
	cout << x;
	return 0;
}
