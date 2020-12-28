#include <bits/stdc++.h>
using namespace std;

int main () {
string s;
cin >>s;
s[0] = s[0] > 'Z' ? s[0] - 32 : s[0];
cout << s << endl;
return 0;
}