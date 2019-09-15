/*
 * https://codeforces.com/contest/1187/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> a;
	vector<int> b;

	int t;
	cin >> t;

	int n;

	while(t--) {

		cin >> n;

		for(int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			a.push_back(temp);
		}

		for(int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			b.push_back(temp);
		}

		vector<int> temp_a(a);
		vector<int> temp_b(b);

		sort(temp_a.begin(), temp_a.end(), greater<>());
		sort(temp_b.begin(), temp_b.end(), greater<>());

		if(temp_a != temp_b) {
			cout << "NO" << endl;
			continue;
		} else {
			if (temp_b == b) {
				cout << "NO" << endl;
				continue;
			} else {
				for(int i =0; i < a.size(); i++) {
					if (a[i] != b[i] && a[i] > b[i]) {
						vector<int>::iterator it = find(b.begin() + i, b.end(), a[i]);
						int pos = distance(b.begin()+i, it);
						sort(a.begin() + i, a.begin() + pos + 1);
					}
					else {
						cout << "NO";
						continue;
					}
				}
			}
		}
	}

	return 0;
}
