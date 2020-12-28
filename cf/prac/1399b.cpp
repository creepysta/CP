#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
            int n;
        cin >> n;
        int a[n], b[n];
        int mina = 1e9+5, minb = 1e9+5;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            mina = min(mina, a[i]);
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            minb = min(minb, b[i]);
        }
        long long moves = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] > mina && b[i] > minb) {
                moves += max(a[i] - mina, b[i] - minb);
            }
            else if(a[i] > mina) moves += a[i] - mina;
            else if(b[i] > minb) moves += b[i] - minb;
        }
        cout << moves << '\n';
    }
    return 0;
}
