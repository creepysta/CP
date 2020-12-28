#include<iostream>
using namespace std;

class abc {
	int i;
	double d;
	char c;
public:
	abc (int i, double d, char c):i(i),d(d),c(c) {};
	operator int () {
		return i;
	}
	operator double () {
		return d;
	}
	operator char () {
		return c;
	}
};

main()
{
	abc a(6, 7.6, 'a');
	cout<<int(a)<<"   "<<double(a)<<"   "<<char(a);
}