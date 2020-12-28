#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
string s;
cin >> s;
int n = s.length();
bool c1 = true,c2 =false;
if(s[0] >= 97) c2 = true;
for(int i = 0; i < n; i++) {
if(i > 0 && s[i] >= 97) c2 = false;
if(s[i] >= 97) c1=false;
}
if(c1) {
transform(s.begin(), s.end(), s.begin(), ::tolower);
} else if(c2) {
transform(s.begin(), s.end(), s.begin(), ::tolower);
s[0] -= 32;
}
cout << s;
return 0;
}