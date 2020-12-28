#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int t; cin >> t;
while(t--) {
ll n; cin >> n;
ld eq;
for(ll i = 2ll; i < n; i++) {
eq = n/(ld)(pow(2,i)-1);
if(ceil(eq) == floor(eq)) {cout << (ll) eq << endl;break;}
}
}
return 0;
}