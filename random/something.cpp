#include<iostream>
using namespace std;
/*
main()
{
	int i;
	int &fn();
	i=fn();
	std::cout<<i;
}

int &fn()
{
	int k=6;
	return k;
}*/
/*
main()
{
	cout<<printf("abcd");
}*/
/*
main()
{
	int i,j,k,c=8;
	cin>>i>>j;
	int max = 0;
	int min = 9999;
	((i>j) && (max = i))||(max=j);
	((i<j) && (min = i))||(min=j);
	while(c--) {
		cin>>k;
		(k>max) && (max=k);
		(k<min) && (min = k);
	}
	cout<<"max: "<<max<<" min: "<<min;
}
main()
{
	char c = '9';
	printf("%d",c);
}*/

void fn(int i)
{++i;}
//void fn1(int *i)
//{++*i;}
void fn(int &k)
{++k;}

main()
{
	int j=5;
	fn(j);
	cout<<j;
	//fn1(&j);
	//cout<<j;
	//fn(j);
	//cout<<j;
}