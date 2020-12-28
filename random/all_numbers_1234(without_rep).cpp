#include<iostream>
using namespace std;

void printArr(int *arr,int l);
void swap(int *a,int *b);
void permute(int *arr,int a,int l);

main()
{
	int arr[]={1,2,3,4};
	permute(arr,0,4);
}

void swap(int *a,int *b)
{
	int t;
	
	t = *a;
	*a = *b;
	*b = t;
}

void printArr(int *arr,int l)
{
	int i;
	for(i=0;i<l;i++) {
		printf("%d",arr[i]);
	}
	printf("\n");
}

void permute(int *arr,int a,int l)
{
	int i;
	if(a==l) {
		printArr(arr,l);
		return;
	} else {
		for(i=a;i<l;i++) {
			swap(arr+a,arr+i);
			permute(arr,a+1,l);
			swap(arr+a,arr+i);
		}
	}
	return;
}
