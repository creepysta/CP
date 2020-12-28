#include<iostream>
using namespace std;

//understanding the friend class
class Frnz;
class SomeGuy {
	int i;
	private:
		void get() {
			cin>>i;
		}
		void show() {
			cout<<i;
		}
	friend Frnz;
};

class Frnz {
	public: int j = SomeGuy::i;
	public: void get() {
		cin>>j;
	}
	public: void show() {
		cout<<j;
	}
};



/* 
class A
{
   int x;
   public:
   friend void show(A &);
};

void show(A &a)
{  
   cin>>a.x;
   cout<<"VALUE OF x IS"<<a.x;
}

int main()
{
  A a;
  show(a);
}

//destructor deletion
class A {
	public:
		A() {
			cout<<this<<"\n";
		}
		~A() {
			cout<<"\n"<<this;
		}
};
//accessing protected functions of a class
class Parent {
	int i;
	float f;
	char c;
	protected:
		void get() {
			cin>>i>>f>>c;
		}
		void show() {
			cout<<i<<f<<c;
		}
};

class Child: protected Parent {
	public:
		void get() {
			Parent::get();
		}
		void show() {
			Parent::show();
		}
};
//understanding operator and type casting in cpp
class ABC {
	int i;
	float f;
	char c;
	public:
		ABC() {
			i=5;
			f=3.5;
			c='a';
		}
		void get() {
			i=5;
			f=3.5;
			c='a';
		}
		operator int() {return i;}
		operator float() {return f;}
		operator char() {return c;}
};

main()
{
	A a[10];
	Child ch;
	ch.get();
	ch.show();
	ABC a;
	a.get();
	cout<<int(a);
	cout<<float(a);
	cout<<char(a);
}

//understanding how destructor is called
class test {
    int this_instance;
    static int number_of_instances;
public:
    test() : this_instance(number_of_instances++)
    {
        std::cout << "constructor invoked for object :"<< this_instance << '\n';
    };
    ~test()
    {
        std::cout << "destructor invoked for object :" << this_instance << '\n';
    };
};

int test::number_of_instances = 0;

int main()
{
  test first_batch[4];

  return 0;
}
 */