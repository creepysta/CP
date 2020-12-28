#include <bits/stdc++.h>
using namespace std;

int main () {
int k, n, b;
cin >> k >> n >> b;
int ans = (b*(b+1)*k)/2 - n;
if (ans <= 0)
cout << 0;
else
cout << ans;
return 0;
}