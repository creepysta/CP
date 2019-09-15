#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n, 0);
    int count = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    while(1) {
        vector<int> todie;
        for(int i = p.size()-1; i > 0; i--) {
            if(p[i] > p[i-1]) {
                todie.push_back(p[i]);
            }
        }
        if(todie.size() == 0) {
            cout << count;
            return 0;
        }
        for(int i : todie) {
            p.erase(find(p.begin(), p.end(), i));
            //proper logic doesn't work it appears in hackerrank
            //p.erase(find(p.end(), p.begin(), i));
        }
        count ++;
        todie.clear();
    }

    return 0;
}
