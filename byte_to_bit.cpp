/*
byte to bit codechef.com
https://www.codechef.com/OCT18B/problems/BITOBYT
*/

#include<iostream>
using namespace std;

int main()
{
    int testcases, n,bit=1,nibble=0,byte=0, fb=1,fn=0,fby=0,count=0,i=1;
    cin>>testcases;
    while(testcases--) {
        cin>>n;
        while(count<n) {
            if(count>=0 && count<2 && !fb) {
                bit+=i;
                fb=1;
            }
            if(count>2 && count<8 && !fn) {
                nibble+=i;
                fb=0;
                fn=1;
            }
            if(count>8 && count<16 && !fby) {
                byte+=i;
                fn=0;
                fby=1;
            }
            if(count>16 && !fb) {
                i *= 2;
                bit+=i;
                fby=0;
                fb=1;
            }
            n -= count;
            count = 0;
            count++;
        }
        cout<<bit<<" "<<nibble<<" "<<byte<<endl;
    }
    return 0;
}
