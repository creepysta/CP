#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int x) {
    if(s.empty() || s.top() <= x) {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s, x);
    s.push(temp);
}


void sort(stack<int> &s) {
    if(s.size() == 1) {
        return;
    }
    int temp = s.top();
    s.pop();
    sort(s);
    insert(s, temp);
}


int main () {
    vector<int> inp {5, 1, 0, 2, 3};
    stack<int> s;
    for(int i : inp)
        s.push (i);
    cout << "Input stack: ";
    reverse(begin(inp), end(inp));
    for(int i : inp)
        cout << i << ' ';
    cout << endl;
    sort(s);
    cout << "Sorted stack: ";
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}
