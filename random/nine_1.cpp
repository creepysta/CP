#include<iostream>
using namespace std;
//i)
template<class T1, class T2>
void fn(T1 t1, T2 t2) {
	cout<<t1<<" "<<t2<<"\t";
}

//ii)
template<class T>
void fn(T t) {
	cout<<t<<" ";
}

main() {
	fn(10,11.8);
	fn("hello",'a');
}