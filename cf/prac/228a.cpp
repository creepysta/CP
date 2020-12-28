#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n = 4;
int a[4];
for(int i = 0; i < 4; i++) cin >>a[i];
sort(a, a+n);
int ans = 0;
for(int i = 0; i < n; i++) {
int j = i;
while(j+1 <n && a[j] == a[j+1]) j++, ans++;
i = j;
}
cout << ans;
return 0;
}