#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll t; cin>> t;
while(t--) {
ll n, m;
cin >> n >> m;
if(m < n) cout << (ll) ((ceil(n/(double)m) * m) - n) << endl;
else cout << (ll) (m - n) << endl;
}
return 0;
}