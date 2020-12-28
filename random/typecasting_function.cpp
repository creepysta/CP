#include<iostream>
using namespace std;

class A {
	int i;
	char c;
	double d;
	public:
		A(int i,char c,double d) : i(i), c(c), d(d) {}
		operator int() {
			return (*this).i;
		}
		operator double() {
			return (*this).d;
		}
		operator char() {
			return (*this).c;
		}
};

int main()
{
	A a(1,'a',4.5);
	cout<<int(a)<<endl;
	cout<<char(a)<<endl;
	cout<<double(a)<<endl;

	return 0;
}