#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int t; cin >> t;
while(t--) {
int x, y, n;
cin >> x >> y >> n;
int q = n/x;
if(n < x) {
cout << y << endl;
} else {
while(true) {
if (x * q + y <= n) {cout << (x*q + y) << endl; break;}
q--;
}
}
}
return 0;
}