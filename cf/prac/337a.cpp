#include <bits/stdc++.h>
using namespace std;

int main() {
int n, k;
cin >> k >> n;
int a[n];
for(int i = 0; i < n; i++) cin >> a[i];
sort(a, a+n);
int ans = 1e9+5;
for(int i = 0; i+k-1 < n; i++) {
ans = min(ans, (a[i+k-1]-a[i]));
}
cout << ans;
return 0;
}