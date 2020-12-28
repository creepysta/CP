#include <bits/stdc++.h>
using namespace std;

int main () {
string s;
cin >>s;
vector<char> nums;
for(int i = 0; i < (int) s.length(); i++) {
if(s[i] != '+') nums.emplace_back(s[i]);
}
sort(nums.begin(), nums.end());
string ans = "";
for(int i = 0; i < (int) nums.size()-1; i++) {
ans += string(1, nums[i]) + "+";
}
ans += string(1, nums[(int) nums.size()-1]);
cout << ans << endl;
return 0;
}