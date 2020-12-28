#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s1 = "12345";
	string s2 = "00:11:22";
	string s3 = "07:05:45PM";
//	int h = stoi(s1);
//	cout << h;
//	cout << endl;
//	stringstream obj(s2);
//	int x;
//	obj >> x;
//	cout <<x;
	char s[s3.length()+1];
	strcpy(s, s3.c_str());
	cout << (strtok(s,":"));

	return 0;
}
