#include<iostream>
using namespace std;

class abc {
	int size, * arr, s;
public:
	abc (int s=0):size(s) {
		if(s<0)
			throw "size can't be negative.\n";
		else
			arr = new int[size];
	}
	void get() {
		cout<<"Enter data:";
		cin>>(*this).arr[s];
	}
	void show() {
		cout<<arr[s];
	}
	void operator [] (int sz) {
		s=sz;
		if(sz>=size)
			throw "index is beyond array size.\n";
		else {
			get();
			show();
		}
	}
};

main() {
	abc a(3);
	try {
		int n;
		cout<<"Enter index: ";
		cin>>n;
		a[n];
	}
	catch(char const * msg) {
		cout<<msg;
	}
}