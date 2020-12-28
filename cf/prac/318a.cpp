#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll n, k;
cin >> n >> k;
if(k <= ceil(n/2.0)) {
cout << (2*k-1);
} else {
k -= ceil(n/2.0);
cout << 2*k;
}
return 0;
}