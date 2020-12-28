//1 3
//3 1
//1 2 3
//3 2 1
//2 1 3

//1 2 4 3
//1 3 2 4
//1 3 4 3
//1 4 3 3


//1 2 3 4
//1 2 4 3

//4 3 2 1
//4 3 2 1

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main() {
	int t;
	cin >> t;
	for(int tt=1; tt <= t; tt++) {
		string s;
		cin >> s;
		fflush(stdout);
		cout << "Case #" << tt << ": ";
		cout << endl << s << endl;
		int n = s.length();
		if(n==1 || n== 0) {
			cout << s << endl;
			return 0;
		}
		bool desc = true;
		for(int i = n-1; i-1 >= 0; i--) {
			if(s[i-1] <= s[i]) desc = false;
		}
		if(desc) cout << s << endl;
		else {
			int i =n;
			while(i-2 >= 0 && s[i-2] >= s[i-1]) i--;
			int tobe = i-2;
			int small = n-1;
			while(small > tobe && s[small] <= s[tobe]) small --;
			swap(s[small], s[tobe]);
			reverse(s.begin()+tobe+1, s.end());
			cout << s << endl;
		}
	}
	return 0;
}
