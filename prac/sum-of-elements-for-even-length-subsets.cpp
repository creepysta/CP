
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<bits/stdc++.h>
#include<cassert>
using namespace std;

/*

{1,2,4,5,9,10,12}


1,2
2,4
4,5
5,9
9,10
10,12

1,2,4,5
2,4,5,9
4,5,9,10
5,9,10,12

1,2,4,5,9,10
2,4,5,9,10,12
*/


int rep(int index, int subsetLen, int totalSize) {
    if(index == 0 || index == totalSize - 1 || subsetLen == totalSize) return 1;
    if(index - (subsetLen-1) >= 0 && index + (subsetLen-1) < totalSize) return subsetLen;
    int whichEnd = min(index, totalSize-1-index);
    int maybe = min(whichEnd+1, subsetLen);
    int spaceToMove = totalSize - subsetLen;
    return min(spaceToMove+1, maybe);
}

int solve(const vector<int> &a) {
    int sum = 0;
    int n = a.size();
    // length of subset
    for(int subsetLen=2; subsetLen <= n; subsetLen+=2) {
        // current element for given subset length (subsetLen)
        // cout << "Current Subset Lenght: " << subsetLen << endl;
        for(int i = 0; i < n; i++) {
            // figure out how many times the current element
            int reps = rep(i, subsetLen, n);
            // cout << a[i] << ": " << i << ' ' << subsetLen << ' ' << reps << endl;
            sum += a[i] * reps;
        }
    }
    return sum;
}

int solve_simulate_sliding_window(const vector<int> &a) {
    int n = a.size();
    vector<int> pref(n+1);
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + a[i-1];
    }
    int ans = 0;
    for(int subsetLen = 2; subsetLen <= n; subsetLen += 2) {
        // cout << "Current subsetLen: " << subsetLen << endl;
        for(int start=0, end=start+subsetLen-1; end < n; start++, end++) {
            // cout << "window | start: " << start << " end: " << end << endl;
            ans += pref[end+1] - pref[start];
        }
    }
    return ans;
}

void test() {
    for(int len = 2; len <= 100; len++) {
        vector<int> a(len);
        iota(begin(a), end(a), 1);
        int simulate = solve_simulate_sliding_window(a);
        int smart = solve(a);
        cout << "simulate: " << simulate << " smart: " << smart << endl;
        assert(simulate == smart);
    }
}

int32_t main()
{
    // given n <= 100;
    // a[i] <= 1000;
    vector<int> a{1,2,4,5,9,10};
    a = {1,2,3,4,5};
    a = {1,2,4,5,9,10,12};
    // int ans = solve(a);
    // int ans = solve_simulate_sliding_window(a);
    // cout << "Ans: " << ans << endl;
    test();
    return 0;
}
