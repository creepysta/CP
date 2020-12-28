#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
string s;
cin >> s;
int low = 0, up= 0;
for(char c : s) {
	if(c < 97) up++;
	else low++;
}
if(low>= up) {
transform(s.begin(), s.end(), s.begin(), ::tolower);
} else {
transform(s.begin(), s.end(), s.begin(), ::toupper);
}
cout << s << endl;
return 0;
}