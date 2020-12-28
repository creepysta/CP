#include <bits/stdc++.h>
using namespace std;

int main() { 
int n;
cin >> n;
int a[n];
int ans = 0, sum = 0;
for(int i = 0; i < n; i++) {
cin >> a[i];
sum += a[i];
}
sort(a, a+n);
int c = 0;
for(int i = n-1; i >=0 && ans<= floor(sum/2); i--) {
ans += a[i];
c++;
}
cout << c;
return 0;
}