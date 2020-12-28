#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n, t;
cin >> n >> t;
string a;
cin >> a;
for(int i = 0; i < n; i++) {
int j = i, p = i;
int tt =t;
while((p < n) and (a[p] == 'B')) p++;
j = p;
if(a[j] == 'G') {
while(j-1 >=0 and t--) swap(a[j], a[j-1]), j--;
}
i = p;
}
cout << a;
return 0;
}