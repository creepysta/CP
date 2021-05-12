#include <bits/stdc++.h>
using namespace std;

void subsetmask(const vector<int> &a, int n) {
	cout << "[]\n";
	for(int mask = 1; mask < (1<<n); mask++) {
		for(int i = 0; i < n; i++) {
			if(mask & (1 << i)) {
				cout << a[i] << ' ';
			}
		}
		cout << endl;
	}
}

void subsetRecur(const vector<int> &a, vector<int> &keep, int start, int n) {
	for(int i : keep) cout << i << ' ';
	cout << endl;
	//cout << "start: " << start << endl;
	for(int i = start; i < n; i++) {
		keep.emplace_back(a[i]);
		//cout << "before call: " << i << ' ' << start<< ' ' << keep.size() << endl;
		subsetRecur(a, keep, i+1, n);
		keep.pop_back();
		//cout << "after call: " << i << ' ' << start<< ' ' << keep.size() << endl;
	}
}

int main() {
	vector<int> a = {1, 2, 3}, keep;
	int n = a.size();
	//subsetmask(a, n);
	subsetRecur(a, keep, 0, n);
	return 0;
}
