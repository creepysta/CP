#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll a, b, n;
        cin >> a >> b >> n;
        ll m = a - (a-b) /2;
        ll ta = a;
        ll tb = b;
        string s;
        while(true) {
            cout << m << endl;
            cin >> s;
            fflush(stdout);
            if(s == "CORRECT") {
                break;
            }
            if(s == "TOO_SMALL") {
                a = m+1;
            }
            if(s == "TOO_BIG") {
                b = m-1;
            }
            m = a - (a-b) / 2;
        }
    }
    return 0;
}
