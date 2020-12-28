#include <bits/stdc++.h>
using namespace std;

void revString(const vector<string> &s, int i) {
	if(i >= (int) s.size()) return;
	revString(s, i+1);
	cout << s[i] << ' ';
}

void revString(const string &s) {
	string word = "";
	for(int i = (int) s.length() - 1; i >= 0; i--) {
		if (s[i] != ' ') word = s[i] + word;
		else {
			cout << word << ' ';
			word = "";
		}
	}
	cout << word;
}

void revWord(const string &s) {
	string word = "", fstring = "";
	for(int i = (int) s.length() - 1; i >= 0; i--) {
		if (s[i] != ' ') word += s[i];
		else {
			fstring = word + ' ' + fstring;
			word = "";
		}
	}
	fstring = word + ' ' + fstring;
	cout << fstring;
}

void revWhole(const string &s, int i) {
	if(i == (int) s.length()) return;
	revWhole(s, i+1);
	cout << s[i];
}

int main() {
	string s = "This is a string";
	cout << s << endl;
	vector<string> a;
	string word = "";
	for(int i = 0; i < (int) s.length(); i++) {
		if(s[i] == ' ' or i == (int) s.length() - 1) {
			if(i == (int) s.length() - 1) word += s[i];
			a.emplace_back(word);
			word = "";
		}
		else {
			word += s[i];
		}
	}
	cout << "recur: reverse array\n";
	revString(a, 0);
	cout << endl << "iterate: reverse array\n";
	revString(s);
	cout << endl << "iterate: reverse word\n";
	revWord(s);
	cout << endl << "recur: reverse whole\n";
	revWhole(s, 0);
	cout << endl;

	return 0;
}


