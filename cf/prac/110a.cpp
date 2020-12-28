#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
string s;
cin >> s;
int a = 0;
unordered_set<int> check= {4,7};
for(char c : s) {
if(c == '4' || c=='7') a++;
}
if(!a) {
cout << "NO" << endl;
return 0;
}
bool isa=true;
while(a) {
int cur = a%10;
if(check.find(cur) == check.end()) {
isa = false;
break;
}
a/=10;
}

if(isa) cout <<"YES";
else cout <<"NO";
cout << endl;
return 0;
}