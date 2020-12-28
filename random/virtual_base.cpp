#include<iostream>
using namespace std;

class A {
protected:
	int i;
public:
	A(int i=0):i(i){}
	virtual void show() =0;
};

class B : public A {
	int j;
public:
	B(int a=0, int b=0) :A(a), j(b) {
	}
	void show() {
		cout<<j<<endl<<i;
	}
};

int main()
{
	B b(2,3);
	b.show();

	return 0;
}
