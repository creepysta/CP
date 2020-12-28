#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool lucky(int num) {
string s = to_string(num);
int n = s.length();
for(char c: s) {
if(!(c== '4' || c=='7')) return false;
}
return true;
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n;
cin >> n;
unordered_set<int> luckies;

for(int i = 4; i <= 777; i++) {
if(!(n%i) && lucky(i)) {
cout << "YES";
return 0;
}
}
cout << "NO";
return 0;
}