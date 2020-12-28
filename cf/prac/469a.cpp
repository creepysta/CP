#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n; cin >> n;
int a[n];
memset(a,0,sizeof(a));
for(int i = 0; i< n; i++) {
int x;
cin >> x;
for(int i = 0; i < x; i++) {
int y; cin >> y;
a[y-1] ++;
}
cin >> x;
for(int i = 0; i < x; i++) {
int y; cin >> y;
a[y-1] ++;
}
}
for(int i = 0; i < n; i++) {
if(!a[i]) {cout << "Oh, my keyboard!";return 0;}
}
cout << "I become the guy.";
return 0;
}