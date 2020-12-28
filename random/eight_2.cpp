// i)

#include<iostream>
using namespace std;

class abc {
	int i;
public:
	abc(int i=0):i(i) {}
	//postfix operator
	int operator ++ (int) {
		return i++;
	}
	//prefix operator
	int operator ++ () {
		return ++i;
	}
	friend void operator << (ostream &, abc &);
};

void operator << (ostream & x, abc & a) {
	x<<a.i;
}

int main()
{
	int i,j;
	abc a(10);
	i = a++;
	j = ++a;
	cout<<i<<" "<<j<<" "<<a;
	// cout<<i<<j<<a;

	return 0;
}



// ii)

// #include<iostream>
// using namespace std;

// class efg;
// class mno;

// class abc {
// 	int i;
// public:
// 	abc(int i=0):i(i) {}
// 	friend istream & operator >> (istream &, abc &);
// 	friend ostream & operator << (ostream &, abc &);
// 	friend mno operator + (abc &, efg &);
// };

// class efg {
// 	int i;
// public:
// 	efg(int i=0):i(i) {}
// 	friend void operator >> (istream &, efg &);
// 	friend ostream & operator << (ostream &, efg &);
// 	friend mno operator + (abc &, efg &);
// };

// class mno {
// 	int i;
// public:
// 	mno(int i=0):i(i) {}
// 	friend void operator << (ostream &, mno &);
// };

// istream & operator >> (istream & i, abc & a) {
// 	i>>a.i;
// 	return i;
// }

// void operator >> (istream & i, efg & e) {
// 	i>>e.i;
// }

// ostream & operator << (ostream & o, abc & a) {
// 	o<<a.i;
// 	return o;
// }

// ostream & operator << (ostream & o, efg & e) {
// 	o<<e.i;
// 	return o;
// }

// void operator << (ostream & o, mno & m) {
// 	o<<m.i;
// }

// mno operator + (abc & a, efg & e) {
// 	return mno(a.i + e.i);
// }

// int main () {
// 	abc a;
// 	efg e;
// 	mno m;
// 	cin>>a>>e;
// 	m = a + e;
// 	cout<<a<<" "<<e<<" "<<m;

// 	return 0;
// }


// iii)

// #include<iostream>
// using namespace std;

// class efg;

// class abc {
// 	int i;
// public:
// 	abc(int i=0):i(i) {}
// 	friend istream & operator >> (istream &, abc &);
// 	friend int operator + (abc &, efg &);
// };

// class efg {
// 	int i;
// public:
// 	efg(int i=0):i(i) {}
// 	friend void operator >> (istream &, efg &);
// 	friend int operator + (abc &, efg &);
// };

// istream & operator >>(istream & i, abc & a) {
// 	i>>a.i;
// 	return i;
// }

// void operator >> (istream & i, efg & e) {
// 	i>>e.i;
// }

// int operator + (abc & a, efg & e) {
// 	return int(a.i+e.i);
// }

// int main()
// {
// 	abc a;
// 	efg e;
// 	cin >> a >> e;
// 	cout<<(a+e);

// 	return 0;
// }



// iv)

// #include<iostream>
// using namespace std;

// class abc {
// 	int i;
// public:
// 	abc (int i=0) : i(i) {}
// 	int operator + (int  i) {
// 		return int((*this).i + i);
// 	}
// };

// int main()
// {
// 	abc a(15);
// 	cout << (a + 5);

// 	return 0;
// }