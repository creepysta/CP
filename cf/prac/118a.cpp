#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'

int main() {
	string s;
	cin >>s;
	unordered_set<char> vow = {'a','e','i','o','u','y'};
	string ans = "";
	for(char c : s) {
		if(c < 97) c += 32;
		if(vow.find(c) == vow.end()) ans += "." + string(1,c);
	}
	cout << ans << endl;
	return 0;
}
