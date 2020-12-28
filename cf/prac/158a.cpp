#include <bits/stdc++.h>
using namespace std;

int main() {
int n, k;
cin >> n >> k;
int a[n];
for(int i = 0; i <n; i++) {
cin >> a[i];
}
int i = 0, ans = 0;
while(i < n && (k-- && a[i])) i++, ans++;
if(a[i]) {
if (i > 0) {
while(i < n and a[i-1] == a[i]) i++, ans ++;
}
}
cout << ans;
return 0;
}
