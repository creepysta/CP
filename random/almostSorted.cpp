#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
    }

    vector<int> temp = a;
    sort(temp.begin(), temp.end());
    
    if(a == temp) {
        cout << "yes";
    } 
    else if(n == 2) {
        cout << "yes\nswap 1 2";
    }
    else if (n > 2) {
        int l=0, r=0;
        for(int i =0 ; i < n-1; i++) {
            if(a[i] > a[i + 1]) {
                l = i;
                r = l + 1;
                while(r < n && a[l] > a[r]) {
                    r ++;
                }
                if(l != r) {
                    break;
                }
            }
        }
        
        if(r - 1 - l == 1) {
            // cout << l << endl << r;
            swap(a[l] , a[r-1]);
            if(a == temp) {
                cout << "yes\nswap " << l + 1 << " " << r;
                return 0;
            } else {
                cout << "no";
                return 0;
            }
        } else {
            // cout << l << endl << r;
            reverse(a.begin() + l, a.begin() + r);
            if(a == temp) {
                cout << "yes\nreverse " << l + 1<< " "  << r;
                return 0;
            } else {
                cout << "no";
                return 0;
            }
        }
    }
    
    return 0;
}
