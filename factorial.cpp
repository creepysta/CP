#include<bits/stdc++.h>

using namespace std;

int main()
{
    int testcases,num,sum=0,i=1;
    cin >> testcases;
    while(testcases--) {
        cin >> num;
        while(floor(num/pow(5,i))) {
            sum += floor(num/pow(5,i));
            i++;
        }
        cout<<sum<<endl;
        sum=0;
        i=1;
    }
    return 0;
}
