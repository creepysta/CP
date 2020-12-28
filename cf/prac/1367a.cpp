#include <bits/stdc++.h>
using namespace std;

int main() {
int t;
cin >>t;
while(t--) {
string s;
cin >> s;
int n = s.length();
string ans = string(1, s[0]);
for(int i = 1; i < n; i+=2) {
ans += s[i];
}
cout << ans << endl;
}
return 0;
}