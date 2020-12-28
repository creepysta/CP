#include <bits/stdc++.h>
using namespace std;

int main() {
int n, x;
cin>> n >> x;
int ans = 0;
for(int i = 0; i < n; i++) {
int xx;
cin >> xx;
if(xx + x <= 5) ans ++;
}
ans /= 3;
cout << ans;
return 0;
}