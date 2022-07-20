#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<string> &ans, int n_open=0, int n_close=0, string _ans="") {
    if(n_open + n_close == n) {
        ans.push_back(_ans);
        return;
    }
    if(n_open < n/2)
        solve(n, ans, n_open+1, n_close, _ans + "(");
    if(n_close < n/2 && n_close < n_open)
        solve(n, ans, n_open, n_close+1, _ans + ")");
}

bool checkBalanced(string s) {
    int open = 0, close = 0;
    for(char c : s) {
        open += c == '(';
        close += c == ')';
        if(close > open)
            return false;
    }
    return open == close;
}

int main() {
    int n = 3;
    vector<string> ans;
    solve(2*n, ans);
    //ans.push_back("((()");
    //ans.push_back("((())))");
    for(string s : ans) {
        cout << s << endl;
        assert(checkBalanced(s));
    }
    return 0;
}
