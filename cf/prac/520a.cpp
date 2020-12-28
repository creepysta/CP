#include <bits/stdc++.h>
using namespace std;

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n; cin >> n;
string s; cin >>s;
int a[26];
memset(a, 0, sizeof(a));
transform(s.begin(), s.end(), s.begin(), ::tolower);
for(int i = 0; i < n;i ++) {
a[s[i]-'a'] ++;
}
for(int i = 0; i < 26; i++) {
if(!a[i]) {
cout << "NO"; return 0;
}
}
cout << "YES";
return 0;
}