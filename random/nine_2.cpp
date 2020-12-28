#include<iostream>
using namespace std;

template<class T> void swap(T *a1, T *a2) {
	T a = *a1;
	*a1 = *a2;
	*a2 = a;
}

template<class A> void sort(A a[], int s) {
	for(int i=0;i<s;i++) {
		for(int j=0;j<s-i-1;j++) {
			if(a[j]>a[j+1]) {
				swap(&a[j],&a[j+1]);
				// A temp = a[j];
				// a[j] = a[j+1];
				// a[j+1] = temp;
			}
		}
	}
	for(int i=0;i<s;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

main() {
	int a[] = {3,2,1,4};
	float f[] = {3.213,3.21,0.123,2.4};
	double d[] = {3.213,3.21,0.123,2.4};
	char c[] = {'d','a','s','w'};
	sort(a,4);
	sort(f,4);
	sort(c,4);
	sort(d,4);
}