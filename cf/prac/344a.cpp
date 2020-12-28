#include <bits/stdc++.h>
using namespace std;

int main() {
int n;
cin >> n;
string prev, now;
cin >> prev;
int ans = 1;
for(int i = 1; i < n ; i++) {
cin >> now;
if(now == prev) continue;
else {
prev = now;
ans ++;
}
}
cout << ans;
return 0;
}