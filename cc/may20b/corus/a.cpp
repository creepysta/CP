#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n, q, c;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<ll> dis(26,0);
        for(char d : s) {
            dis[d-97] += 1;
        }
        while(q--) {
			cin >> c;
            ll totalPending = 0;
            for(int i = 0; i < 26; i++) {
                if(c < dis[i]) {
                    totalPending += dis[i] -c;
                }
            }
            cout << totalPending << endl;
        }
    }
    return 0;
}
