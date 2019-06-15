/*

https://www.hackerrank.com/challenges/simple-text-editor/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign


*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    vector<string> s = {""};
    int operations;
    cin >> operations;
    int i = 0;
    while(operations--) {
        string args = "";
        int op;
        int k;
        cin >> op;
        if (op == 1) {
            cin >> (args);
            i++;
            s.push_back(s[i-1] + args);
        }
        else if (op == 2) {
            cin >> k;
            string temp = s[i];
            temp.erase(temp.end() - k, temp.end());
            s.push_back(temp);
            i++;
        }
        else if (op == 3) {
            cin >> k;
            cout << s[i][k-1] << endl;
        }
        else if (op == 4) {
            i--;
            if(i == 0) {
                continue;
            }
            s.pop_back();
        }
    }
    return 0;
}
