/*
projecteuler.net/problem=217
A positive integer with k (decimal) digits is called balanced if its first ⌈k/2⌉ digits sum to the same value as its last ⌈k/2⌉ digits, where ⌈x⌉, pronounced ceiling of x, is the smallest integer ≥ x, thus ⌈π⌉ = 4 and ⌈5⌉ = 5.

So, for example, all palindromes are balanced, as is 13722.

Let T(n) be the sum of all balanced numbers less than 10n.
Thus: T(1) = 45, T(2) = 540 and T(5) = 334795890.

Find T(47) mod 315

hackerrank.com

*/

#include<bits/stdc++.h>
using namespace std;
/*
main()
{
    const int = 1004535809
    long int B,L;
    int i,j,decimal=0;
    cin>>B>>L;
    vector<int> a;
    for(i=L-1;i>=0;i--) {
        int n;
        cin>>n;
        a.push_back(n);
        decimal += a[i]*pow(B,i);
    }
//    cout<<decimal;
    i=1;
    while(i<=decimal){

    }
}
*/

main()
    const int den = 14348907;
}
