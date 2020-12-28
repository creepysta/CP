#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    uint64_t n;
    cin >> n;
    map<string, uint64_t> m;
    for(uint64_t i = 0; i < n; i++) {
        string s;
        uint64_t num;
        cin >> s >> num;
        m[s] = num;
    }
    for(uint64_t i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(m.find(s) != m.end()) {
            cout << s << '=' << m[s] << '\n';
            continue;
        }
        cout << "Not found\n";
    }
}

