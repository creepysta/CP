#include <bits/stdc++.h>

using namespace std;


int main() {
	int n, k;
	vector<int> notes;
	cin >> n >> k;
	for(int i = 0; i<n; i++) {
		int temp;
		cin >> temp;
		notes.push_back(temp);
	}
	int count = 0;
	int i = 0, j = 1;
	int sum = notes[i];
	while(i < notes.size()) {
		if(sum == k) {
			count ++;
		}
		while(sum<k) {
			sum += notes[j++];
			if(sum == k) {
				count ++;
			}
		}
		i++;
		j = i + 1;
		sum = notes[i];

	}
	cout << count;

	return 0;
}

