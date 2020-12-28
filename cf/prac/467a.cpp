#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n;
cin >> n;
int ans=0;
for(int i = 0; i<n; i++) {
int p,q;
cin >> p >> q;
ans += q-p >= 2 ? 1 : 0;
}
cout << ans << endl;
return 0;
}