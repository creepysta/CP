#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<string> &ans, int ones, int zeroes=0, string pref="") {
    if(n == 0) {
        ans.push_back(pref);
        return;
    }
    solve(n-1, ans, ones+1, zeroes, pref + "1");
    if(zeroes < ones)
        solve(n-1, ans, ones, zeroes+1, pref + "0");
}


int main() {
    int n = 6;
    vector<string> ans;
    solve(n, ans, 0);
    //ans.push_back("101001010");
    //ans.push_back("000101010");
    for(string s : ans) {
        cout << s << endl;
        for(int i = 0; i < n; i++) {
            int ones = 0, zeroes = 0;
            for(int j = 0; j < n-i; j++) {
                ones += s[j] == '1';
                zeroes += s[j] == '0';
            }
            assert(ones >= zeroes);
        }
    }
    return 0;
}
