#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n; cin >> n;
vector<int> ans(n+1, 0);
for(int i = 1; i <= n; i++) {
int x; cin >> x;
ans[x] = i;
}
for(int i =1; i<=n;i ++) {
cout << ans[i] << ' ';
}
return 0;
}