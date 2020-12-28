#include<iostream>
using namespace std;

class ABC {
public:
	virtual void get() {} // = 0;
	virtual void show() {} // = 0;
};

class EFG : public ABC {
private:
	int i;
public:
	void get() {
		cin>>i;
	}
	void show() {
		cout<< i;
	}
};

main()
{
	ABC a;
	a.show();a.get();// ABC *a = new EFG;
	EFG b;
	b.get();
	b.show();
	// a->get();
	// a->show();
}