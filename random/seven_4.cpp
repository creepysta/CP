#include<iostream>
#include<cmath>
using namespace std;

class Shape {
// private:
protected:
	string s;
public:
	Shape (string s="") : s(s){
		cout << s << " ";
	}
	virtual void perimeter() = 0;
	virtual void area() = 0;
};

class Circle : public Shape {
private:
	const double pi = 3.14159265358979323846;
	int radius;
public:
	Circle(string s, int r) : Shape(s), radius(r){}
	void perimeter() {
		cout << "Perimeter " << (2*pi*radius);
	}
	void area() {
		cout << "\tArea " << (2*pi*pow(radius,2)) <<  endl;
	}
};

class Rectangle : public Shape {
private:
	double length, breadth;
public:
	Rectangle(string s, double l, double b) : Shape(s), length(l), breadth(b) {}
	void perimeter() {
		cout << "Perimeter " << 2* ( length + breadth);
	}
	void area() {
		cout << "\tArea " << length * breadth << endl;
	}
};

class RegularPolygon : public Shape {
private:
	const double pi = 3.14159265358979323846;
	double sides;
	int n;
public:
	RegularPolygon(string s, double sides, int n): Shape(s), sides(sides), n(n) {}
	void perimeter() {
		cout << "Perimeter " << sides * n;
	}
	void area() {
		double a = sides/(2*tan(180/n));
		cout << "\tArea " << (sides * n * a)/2 << endl;
	}
};

int main()
{
	int ch;
	string s;
	cout<<"1.Circle 2.Square 3.Rectangle 4.Regular Polygon 5.Exit"<<endl;
	while(ch != 5) {
		cout<<"Enter choice: ";
		cin>>ch;
		switch(ch) {
			case 1: {
				double r;
				s = "Circle";
				cout<<"Enter radius: ";
				cin>>r;
				Circle obj(s,r);
				obj.perimeter();
				obj.area();
			}
			break;

			case 2: {
				double l,b;
				s = "Square";
				cout<<"Enter Length and breadth:\n";
				cin>>l>>b;
				Rectangle obj(s,l,b);
				obj.perimeter();
				obj.area();
			}
			break;

			case 3: {
				double l,b;
				s = "Rectangle";
				cout<<"Enter Length and breadth:\n";
				cin>>l>>b;
				Rectangle obj(s,l,b);
				obj.perimeter();
				obj.area();
			}
			break;

			case 4: {
				double l,n;
				s = "Regular Polygon";
				cout<<"Enter Length of sides and number of sides:\n";
				cin>>l>>n;
				RegularPolygon obj(s,l,n);
				obj.perimeter();
				obj.area();
			}
			break;

			case 5:
			return 0;
			break;

			default:
			cout<<"Wrong Choice\n";
		}
	}
}