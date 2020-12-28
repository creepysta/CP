#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n;
cin >> n;
double ans = 0;
for(int i = 0; i < n; i++) {
int x; cin >> x;
if(x) {
ans += (double)x/100.0;
}
}
cout << (ans/(double)n*100.0);
return 0;
}