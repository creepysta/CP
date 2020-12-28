#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
string s;
cin >> s;
unordered_set<char> check = {'H', 'Q', '9'};
bool one =false;
for(char c : s) {
if(check.find(c) != check.end()) {
one = true;
break;
}
}
if(one) cout << "YES";
else cout << "NO";
cout << endl;
return 0;
}