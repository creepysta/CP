#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
string s1, s2;
cin >> s1 >> s2;
int n1 = s1.length();
for(int i = 0; i < n1; i++) {
if(s1[i] == s2[i]) cout << 0;
else cout << 1;
}
return 0;
}