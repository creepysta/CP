#include <bits/stdc++.h>
using namespace std;

int main () {
int n;
cin >> n;
int a=0, b=0, c=0;
while(n--) {
int a1,a2, a3;
cin >> a1 >> a2 >> a3;
a += a1;
b += a2;
c += a3;
}
if(!a && !b && !c) cout << "YES";
else cout << "NO";

return 0;
}