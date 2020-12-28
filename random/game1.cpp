#include<iostream>
using namespace std;

int isPrime(int n)
{
	int i;
	if(n==2)
		return 1;
	for(i=2;i*i<=n;i++) {
		if(n%i == 0)
			return 0;
	}
	return 1;
}

void swap(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

main()
{
	const int ans[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int given[3][3], i,j,k,x;
	cout<<"Enter a matrix to begin:\n";
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			cin>>given[i][j];
	cout<<"Given Matrix:\n";
	for(i=0;i<3;i++) {
		for(j=0;j<3;j++)
			cout<<given[i][j]<<"\t";
		cout<<endl;
	}
	i=0;j=0;
	while(i>=0&&i<3) {
		j=0;
		while(j>=0&&j<3) {
			x = given[i][j];
			if(x != ans[i][j]) {
				if(isPrime(x+given[i][j+1]))
					swap(&given[i][j],&given[i][j+1]);
				else if(isPrime(x+given[i+1][j]))
					swap(&given[i][j],&given[i+1][j]);
				else if(isPrime(x+given[i-1][j]))
					swap(&given[i][j],&given[i-1][j]);
				else if(isPrime(x+given[i][j-1]))
					swap(&given[i][j],&given[i][j-1]);
			}
			j++;
		}
		if(j>=3)
			i++;
		if(i>=3)
			break;
	}
	cout<<"Final Answer:\n";
	for(i=0;i<3;i++) {
		for(j=0;j<3;j++)
			cout<<given[i][j]<<"\t";
		cout<<endl;
	}
}
