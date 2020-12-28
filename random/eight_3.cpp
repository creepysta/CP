// i)

// #include<iostream>
// using namespace std;

// class Complex {
// 	int r, i;
// public:
// 	Complex(int r = 0, int i = 1) : r(r), i(i){}
// 	Complex operator + (Complex &b) {
// 		return Complex(r+b.r, i+b.i);
// 	}
// 	void show() {
// 		if(i > 0)
// 			cout << r<<" + i"<< i;
// 		else
// 			cout << r <<"i"<< i;
// 	}
// };

// int main()
// {
// 	Complex a(1,2), b(2,3),c;
// 	c = a + b;
// 	c.show();
// }



// ii)

// #include<iostream>
// using namespace std;
// class StringCompare {
// 	string s;
// public:
// 	StringCompare(string s=""):s(s){}
// 	bool operator > (StringCompare & s2) {
// 		if(s.size() > s2.s.size())
// 			return true;
// 		return false;
// 	}
// 	bool operator < (StringCompare & s2) {
// 		if(s.size() < s2.s.size())
// 			return true;
// 		return false;
// 	}
// 	bool operator == (StringCompare & s2) {
// 		if(s == s2.s )
// 			return true;
// 		return false;
// 	}
// 	void show() {
// 		cout<<s<<endl;
// 	}
// };

// int main()
// {
// 	StringCompare s("hello"), t("world");
// 	if(s>t)
// 		s.show();
// 	else if(s==t) {
// 		s.show();
// 		t.show();
// 	}
// 	else
// 		t.show();
// }



// iii)

#include<iostream>
using namespace std;

class CharOperation {
public:
	char c;
	CharOperation (char c='a') : c(c) {}
	char operator ++ () {
		if (c!='z')
			return ++c;
		return 'a';
	}

	char operator -- () {
		if (c!='a')
			return --c;
		return 'z';
	}
};

int main()
{
	CharOperation c;
	cout<<++c;
	cout<<--c;
}