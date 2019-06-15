/*
https://codeforces.com/contest/1072/problem/B
i/p
4
3 3 2
1 2 0

o/p
1 3 2 0

i/p
3
1 3
2 0

o/p
NO
*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int length,*a,*b,*t;
    cin>>length;
    a = new int[length-1];
    b = new int[length-1];
    t = new int[length];
    for(int i =0;i<length-1;i++) {
        cin>>a[i];
    }
    // for(int i =0;i<length-1;i++) {
    //     cout<<i<<":"<<a[i]<<endl;
    // }
    for(int i =0;i<length-1;i++) {
        cin>>b[i];
    }
    for(int i =0;i<length-1;i++) {
        int t1,t2;
        t1 = a[i];t2 = b[i];
        if(a[i] == t1|t2 && b[i] == t1&t2) {
            t[i] = t1;
            t[i+1] = t2;
        }
        else {
            t2 = a[i];t1 = b[i];
            if(a[i] == t1|t2 && b[i] == t1&t2)  {
                t[i] = t1;
                t[i+1] = t2;
            }
            else {
                cout<<"No\n";
                return 0;
            }
        }
    }
    // int length;
    // vector<int> a,b,t;
    // cin>>length;
    // for(int i =0;i<length-1;i++) {
    //     int num;
    //     cin>>num;
    //     a.push_back(num);
    // }
    // for(int i =0;i<length-1;i++) {
    //     int num;
    //     cin>>num;
    //     b.push_back(num);
    // }
    // for(int i =0;i<length-1;i++) {
    //     int t1,t2;
    //     t1 = a[i];t2 = b[i];
    //     if(a[i] == t1|t2 && b[i] == t1&t2)  {
    //         t.push_back(t1);
    //         t.push_back(t2);
    //     }
    //     else {
    //         t2 = a[i];t1 = b[i];
    //         if(a[i] == t1|t2 && b[i] == t1&t2)  {
    //              t.push_back(t1);
    //              t.push_back(t2);
    //         }
    //         else {
    //             cout<<"No\n";
    //             return 0;
    //         }
    //     }
    // }
    cout<<"Yes\n";
    for(int i=0;i<length;i++) {
        cout<<t[i]<<" ";
    }
    cout<<endl;
    return 0;
}
