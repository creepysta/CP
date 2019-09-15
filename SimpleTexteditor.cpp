/*
 *
 * https://www.hackerrank.com/challenges/simple-text-editor/problem?h_r=internal-search
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    vector<string> s;
    long operations, k, op;
    cin >> operations;
    string args, temp;
    //bool flag = false;

    s.push_back("");
    while(operations--) {
        args = "";
        temp = "";
        cin >> op;
        switch(op) {
            case 1:
                cin >> args;
                temp = s[s.size()-1];
                temp.append(args);
                s.push_back(temp);
                // cout << "From 1: " << s[s.size()-1] << " " << temp << " " << s.size() << endl;
                break;
            case 2:
                cin >> k;
                temp = s[s.size()-1];
                temp.erase(temp.size()-k);
                s.push_back(temp);

                // cout << "From 2: " << s[s.size()-1] << " " << temp << " " << s.size() << endl;
            
                break;
            case 3:
                cin >> k;
                cout << s[s.size()-1][k-1] << endl;
                // cout << "From 3: " << s[s.size()-1] << endl;
                break;
            case 4:
                // cout << "From 4: " << s[s.size()-1] << " " << temp << "\t";
                s.pop_back();
                // cout << s[s.size()-1] << endl;
                break;
        }
        // flag = true;
        // for(int i = 0; i < s.size(); i++) {
        //     cout << s[i] << endl;
        // }
    }
    return 0;
}
