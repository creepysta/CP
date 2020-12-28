#include<iostream>
using namespace std;

main()
{
	int i;
	int &fn();
	i = fn();
	cout<<i;
}

int &fn()
{
	int i = 7;
	return i;
}

/*
//overloading fn without inheritance causes ambiguity
void fn(int *i) {
	*i=21;
}
void fn(int &i) {
	i = 76;
}
void fn(int i) {
	i = 8;
}

main()
{
	int i;
	cin>>i;
	fn(i);
	fn(&i);
	fn(i);
}
*/