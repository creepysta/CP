
// > operator overloading for string
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
bool operator > (string s1, string s2) {
	if(s1.size() > s2.size())
		return  true;
}

int main()
{

	string s = "henllo" , t = "world";
	if(s>t)
		cout << "Henllo World" << endl; 
	else
		cout<<"noob";
	return 0;
}
*/

//friend function doubt
class A {
	char *message = "From A!\n";
	public:
		friend void show(A &a);
};

void show(A &a) {
	puts(a.message);
}

int main()
{
	A a;
	show(a);
}
