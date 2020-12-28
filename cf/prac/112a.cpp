#include <bits/stdc++.h>
using namespace std;

int main() {
string s1, s2;
cin >> s1 >> s2;
for(int i=0; i < (int) s1.length(); i++) {
s1[i] = s1[i] < 97 ? s1[i] + 32 : s1[i];
s2[i] = s2[i] < 97 ? s2[i] + 32 : s2[i];
if(s1[i] < s2[i]) {
cout << -1 << endl;
return 0;
}
else if(s1[i] > s2[i]) {
cout << 1 << endl;
return 0;
}
}
cout << 0 << endl;
return 0;
}