#include<iostream>
using namespace std;

void fibonacci1(int n)
{
	int a=0,b=1,sum=0;
	if(n==1) {
		cout<<b<<"\n";
	} else {
		cout<<b<<"\n";
		for(int i=1;i<n;i++) {
			sum=a+b;
			cout<<sum<<"\n";
			a=b;
			b=sum;
		}
	}
}

int fibonacci(int n)
{
	if(n==1) {
		return 1;
	}
	else if(n==0)
		return 0;
	else
		return fibonacci(n-1)+fibonacci(n-2);
}

main()
{
	int n;
	cout<<"Enter the number of terms of fibonacci series that you wish to see: ";
	cin>>n;
	fibonacci1(n);
	fibonacci(n);
}