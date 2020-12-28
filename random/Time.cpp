#include<iostream>
using namespace std;
class Time
{
	public:
	int h,m,s;
	Time(){h=0;m=0;s=0;}
	Time(int hh,int mm,int ss){h=hh;m=mm;s=ss;}
	static void add(Time &a,Time &b)
	{
		int hh,mm,ss;
		ss=a.s+b.s;
		if(ss>=60)
		{
			ss=ss-1;
			mm=a.m+b.m+1;
		}
		else
		{
			mm=a.m+b.m;
		}
		if(mm>=60)
		{
			mm=mm-1;
			hh=a.h+b.h+1;
		}
		else
		{
			hh=a.h+b.h;
		}
		if(hh>=23 && mm>=59 && ss>=59 )
		{
			hh=0;mm=0;ss=0;
		}
		cout<<hh<<":"<<mm<<":"<<ss;
	}
	void display()
	{
		cout<<h<<":"<<":"<<m<<":"s;
	}
};
//int Time::h=0,Time::m=0,Time::s=0;

int main()
{
	Time a(2,3,4),b(9,23,9);
	Time::add(a,b);
}
