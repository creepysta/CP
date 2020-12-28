#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        bool pos = true;
        for(int &i : a) cin >> i;
        sort(a, a+n);
        for(int i = 0 ; i < n-1; i++) {
            if(abs(a[i] - a[i+1]) > 1) {
                pos = false;
                cout << "NO" << endl;
                break;
            }
        }
        if(pos) cout << "YES" << endl;
    }
    return 0;
}