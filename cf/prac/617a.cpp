#include <bits/stdc++.h>
using namespace std;

int main() {
int n;
cin>> n;
int ans=0;
while(n > 0) {
if(n/5) (ans+=n/5) && (n %= 5);
else if(n/4) (ans+=n/4) && (n %=4);
else if(n/3) (ans+=n/3) && (n %=3);
else if(n/2) (ans+=n/2) && (n %=2);
else (ans += 1) && (n%=1) ; 
}
if(!ans) ans++;
cout << ans;
return 0;
}