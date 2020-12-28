#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n; cin >> n;
int od = 0, ev=0;
int ao =0, ae = 0;
for(int i = 0; i < n; i++) {
int x;
cin >> x;
if(x%2) od ++, ao = i+1;
else ev++, ae = i+1;
}
if(od > ev)
cout << ae;
else cout << ao;
return 0;
}