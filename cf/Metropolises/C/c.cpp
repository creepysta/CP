#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	int c= 0;
	string s;
	cin >> s;
	
	if(n %2 != 0) {
		cout << "No" << endl;
	} else {
		for(char i: s) {
			if ( i== '(') {
				c += 1;
			} else if ( i== ')') {
				c -= 1;
			}cd ..
		}
		
		if (c == - 1 || c == 1 || c == 0) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	
	return 0;
}
