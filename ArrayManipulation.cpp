/*
 *https://www.hackerrank.com/challenges/crush/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
 *
 */

#include <bits/stdc++.h>
using namespace std;


int main() {
    long int n,m,a,b,k,i,j,max=0,x=0;

    cin >> n >> m;
    long int *arr=new long int[n+1]();

    for(i = 0;i < m;i++)
    {
        cin >> a >> b >> k;
        arr[a] += k;
        if((b+1)<=n) 
            arr[b+1] -= k;
        // for(long int j =1; j <= n; j++)
        //     cout << arr[j] <<" ";
        // cout << endl;
    }

    for(i = 1; i <= n; i++)
    {
        x = x + arr[i];
        if(max < x)
            max=x;
        // cout << endl << x << " ";
    }

    cout << max;
    return 0;
}
