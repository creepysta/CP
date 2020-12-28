#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int ans = 0;
int n;
cin >> n;
for(int i = 0; i < n; i++) {
char x; cin >> x;
if(x == 'A') ans ++;
else ans --;
}
if(ans < 0) cout << "Danik";
else if(!ans) cout << "Friendship";
else cout << "Anton";
return 0;
}