#include <bits/stdc++.h>
using namespace std;

int main() {
int n;
cin >> n;
int m = 0, c = 0;
int a=0, b=0;
for(int i = 0; i < n; i++) {
cin >> a >> b;
if(a > b) m++;
if(a<b) c++;
}
if(m==c) cout << "Friendship is magic!^^";
else cout << (c > m ? "Chris" : "Mishka");
return 0;
}