#include <iostream>
using namespace std;

int32_t main() {
	unsigned long long int check = 1ULL << 63;
	cout << sizeof(check) << ' ' << check << endl;
	return 0;
}
