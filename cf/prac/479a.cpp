#include <bits/stdc++.h>
using namespace std;
int main() {
int a, b, c;
cin >> a >> b >> c;
int ans[7];
memset(ans, 0, sizeof(ans));
ans[0] = a*b*c;
ans[1] = (a+b)*c;
ans[2] = a*(b+c);
ans[3] = a + b + c;
cout << *max_element(ans, ans+7);
return 0;
}