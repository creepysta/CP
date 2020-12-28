#include <bits/stdc++.h>
using namespace std;

int main () {
string a;
cin >> a;
int n = a.length();
int c = 1;
for(int i = 0; i < n-1; i++) {
if(a[i] == a[i+1]) {
c++;
if(c== 7) {
cout << "YES";
return 0;
}
continue;
}
c = 1;
}
cout << "NO";
return 0;
}