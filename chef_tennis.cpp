#include<iostream>
using namespace std;

int main()
{
    int n,p1,p2,k;
    cin>>n;
    while(n--) {
        cin>>p1>>p2>>k;
        if(int(((p1+p2)/k))%2!=0)
            cout<<"COOK\n";
        else
            cout<<"CHEF\n";
    }
    return 0;
}
