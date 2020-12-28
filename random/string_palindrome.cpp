#include<iostream>
using namespace std;

int main()
{
	int count = 0;
	string s = "A man a plan a canal panama";
	for(int i = 0; i < s.length(); i++)
		if(s[i] > 65 && s[i] < 90)
			s[i].c_str() = s[i].c_str() + 26;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == ' ') {
			count++;
			for(int j = i; j < s.length(); j++) {
				s[j] = s[j+1];
			}
		}
	}
	for(int i = 0; i < s.length()-count; i++)
		cout << s[i];

	return 0;
}
