// i)

// #include<iostream>
// using namespace std;

// class abc {
// 	int i;
// public:
// 	abc(int i):i(i) {}
// 	int operator + (abc &b) {
// 		return int((*this).i+b.i);
// 	}
// 	int operator + (int i) {
// 		// cout<<i<<endl<<(*this).i<<endl;
// 		return ((*this).i + i);
// 	}
// 	friend int operator + (int,abc&);
// };

// int operator + (int i, abc &a) {
// 	return (i+a.i);
// }

// main()
// {
// 	abc a(10), b(15), c(20);
// 	cout<<(a+b+c)<<endl;
// 	cout<<(a+5)<<endl;
// }

//ii)

// #include<iostream>
// using namespace std;

// class abc {
// public:
// 	int i;
// 	abc(int i=0):i(i) {}
// 	abc operator - (abc &b) {
// 		return abc((*this).i-b.i);
// 	}
// 	void show() {
// 		cout<<i<<endl;
// 	}
// };

// int main() {
// 	abc a(10), b(5),c;
// 	c = a-b;
// 	c.show();

// 	return 0;
// }


// iv)

#include<iostream>
using namespace std;

class mno;
class efg;

class abc {
	int i;
public:
	abc(int i=0):i(i) {}
	friend mno operator * (abc &, efg &);
};

class efg {
	int i;
public:
	efg(int i=0):i(i){}
	friend mno operator * (abc &, efg &);
};

class mno {
	int i;
public:
	mno(int i=0):i(i) {}
	void show() {
		cout<<i<<endl;
	}
};

mno operator * (abc & a, efg & e) {
	return mno(a.i*e.i);
}

main()
{
	abc a(10);
	efg e(15);
	mno m;
	m = a*e;
	m.show();
}


//v)

// #include<iostream>
// using namespace std;

// class abc {
// public:
// 	string s;
// 	abc(string i=""):s(i) {}
// 	abc operator + (abc &b) {
// 		return abc((*this).s+b.s);
// 	}
// 	void show() {
// 		cout<<s<<endl;
// 	}
// };

// int main() {
// 	abc a("Hello"), b("World"),c;
// 	c = a+b;
// 	c.show();

// 	return 0;
// }


// vi)
// #include<iostream>
// using namespace std;

// class efg;

// class abc {
// 	int i;
// public:
// 	abc(int i=0):i(i) {}
// 	void getval() {
// 		cin>>i;
// 	}
// 	void show() {
// 		cout<<i<<endl;
// 	}
// 	friend bool operator > (abc &,efg &);
// };

// class efg {
// 	int i;
// public:
// 	efg(int i=0):i(i) {}
// 	void getval() {
// 		cin>>i;
// 	}
// 	void show() {
// 		cout<<i<<endl;
// 	}
// 	friend bool operator > (abc &,efg &);
// };

// bool operator > (abc &a,efg &b) {
// 	if(a.i>b.i)
// 		return true;
// 	return false;
// }

// int main()
// {
// 	abc a;
// 	efg e;
// 	a.getval();
// 	e.getval();
// 	if(a>e)
// 		a.show();
// 	else
// 		e.show();
// }

// vii)
// #include<iostream>
// using namespace std;

// class abc {
// 	int i;
// public:
// 	abc (int i=0):i(i) {}
// 	// abc operator | (abc & x) {
// 	// 	abc c;
// 	// 	c.i = i|x.i;
// 	// 	return c;
// 	// }
// 	int operator | (abc & x) {
// 		return int(i|x.i);
// 	}
// 	friend void operator << (ostream &, abc &);
// };

// // void operator << (ostream &x, abc &a) {
// // 	x<<a.i;
// // }

// main()
// {
// 	abc a(5),b(3),c;
// 	// c = a&b;
// 	// cout<<c;
// 	cout<<(a|b);
// }

