#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n; cin >> n;
int a[n];
for(int i = 0; i < n; i++) cin >> a[i];
int ans = -2;
for(int i = 0; i <n; i++) {
int j = i;
while(j+1 < n and a[j] <= a[j+1]) j++;
ans = max(ans, j-i+1);
i = j;
}
cout << ans;
return 0;
}