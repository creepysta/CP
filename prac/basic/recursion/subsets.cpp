#include <bits/stdc++.h>
using namespace std;

void solve(string s, int n, string ans="") {
    if(n == 0) {
        reverse(begin(ans), end(ans));
        cout << "'" << ans << "'" << '\n';
        return;
    }
    solve(s, n-1, ans);
    solve(s, n-1, ans+=s[n-1]);
}

int main() {
    string s = "abc";
    solve(s, s.length());
    return 0;
}
