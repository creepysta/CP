#include <bits/stdc++.h>
using namespace std;

// 001 010 011 100 101 110 111
// 001 010 011 100 110 111

void mask(const vector<int> &a) {
	int n = a.size();
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			for(int k = i; k <= j; k++) {
				cout << a[k] << ' ';
			}
			cout << endl;
		}
	}
	return;
}

void recur(const vector<int> &a) {

}

int32_t main() {
	vector<int> a = {1, 2, 3, 4	};
	mask(a);
	return 0;
}
