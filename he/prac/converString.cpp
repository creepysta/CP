#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s, t;
		cin >> s >> t;
		int cost = 0;
		for(int i = 0; i < s.size(); i++) {
			int diff =  t.at(i) - s.at(i);
			while(diff) {
				if(diff < 0) {
					if(abs(diff) > 13) {
						t.at(i) = 65 + (t.at(i)%26 + 13) % 26;
					}else {
						s.at(i) = 65 + (s.at(i)%26 + 1)%26;
					}
				} else if (diff < 13 && diff > 0) {
					s.at(i) += 1;
				}
				else if(diff >= 13) {
					s.at(i) = 65 + (s.at(i)%26 + 13) % 26;
				}
				cost += 1;
				diff =  t.at(i) - s.at(i);
			}
		}
		cout << cost << endl;
	}
	return 0;
}
