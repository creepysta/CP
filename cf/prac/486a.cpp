#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll n;
cin >> n;
ll m = ceil(n/2.0);
ll od = -1 * (unsigned long long) (m * m);
m = n/2;
ll ev = (unsigned long long) m*(m+1);
ll ans = od + ev;
cout << ans;
return 0;
}