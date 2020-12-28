#include <bits/stdc++.h>
using namespace std;

int main () {
unordered_set<char> see;
string s;
cin >> s;
int ans = 0;
for(char c : s) {
if(see.find(c) == see.end()) ans ++;
see.insert(c);
}
if(ans & 1)
cout << "IGNORE HIM!";
else
cout << "CHAT WITH HER!";

return 0;
}