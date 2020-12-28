#include<iostream>
#include<cmath>
using namespace std;

void greatest(double a, double b)
{
	cout<<"The largest among the two numbers is: "<<ceil(((a+b)/2 + abs(a-b)/2));
}

void min(double a, double b)
{
	cout<<"The smallest among the two numbers is: "<<ceil(((a+b)/2 - abs(a-b)/2));
}

main()
{
	double a, b;
	cin>>a>>b;
	greatest(a,b);
	cout<<"\n";
	min(a,b);
}