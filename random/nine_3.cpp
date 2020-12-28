// #include<iostream>
// using namespace std;

// template<class T> class abc {
// 	T t;
// public:
// 	abc(T t):t(t){
// 		cout<<t<<" ";
// 	}
// };

// main()
// {
// 	abc<int> a(10);
// 	abc<float> b(4.5);
// 	abc<char> c('x');
// }


#include<iostream>
using namespace std;

template<class T,int s> class abc {
	T *t;
	// int size;
public:
	abc() {
		t = new T[s];
		cout<<s;
	}
	void get() {
		cout<<s;
		for(int i=0;i<s;i++) {
			cin>>t[i];
		}
	}
	void sort() {
		for(int i=0;i<s;i++) {
			for(int j=0;j<s-i-1;j++) {
				if(t[j]>t[j+1]) {
					T temp = t[j];
					t[j] = t[j+1];
					t[j+1] = temp;
				}
			}
		}
	}
	void show() {
		for(int i=0;i<s;i++) {
			cout<<t[i]<<" ";
		}
	}
};

main()
{
	abc<int, 5> a;
	a.get();
	a.sort();
	a.show();
}