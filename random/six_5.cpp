#include<iostream>
using namespace std;
class mno;
class efg;
class pqr;
class abc
{
    static int i;
    public:
    virtual void get(){cin>>i;}
    virtual void show(){cout<<" ABC "<<i;}
};
int abc :: i = 0;
class efg : virtual public abc 
{
    int i;
    public:
    void get(){abc::get();cin>>i;}
    void show(){abc::show();cout<<" EFG "<<i;}
};

class mno : virtual public abc 
{
    int i;
    public:
    void get(){abc::get();cin>>i;efg::get();}
    void show(){abc::show();cout<<" MNO "<<i;}
};

class pqr : public efg,public mno
{
    int i;
    efg e;
    mno m;
    public:
    void get(){
        e.get();
        m.get();
        cin>>i;
    }
    void show(){
        e.show();
        m.show();
        cout<<" PQR "<<i;
    }
};

main()
{
    // abc *p;
    // p=new pqr;
    // p->get();
    // p->show();
    pqr p;
    p.get();
    p.show();
}