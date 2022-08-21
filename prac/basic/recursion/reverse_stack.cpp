#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int x) {
    if(s.empty()) {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s, x);
    s.push(temp);
}


void reverse(stack<int> &s) {
    if(s.empty()) return;
    int val = s.top();
    s.pop();
    reverse(s);
    insert(s, val);
}

int main() {
    int n = 5;
    stack<int> s;
    for(int i = 1; i <= n; i++) {
        s.push(i);
    }
    cout << "Input stack: ";
    for(int i = n; i >= 1; i--) {
        cout << i << " ";
    }
    cout << endl;
    reverse(s);
    cout << "Reversed stack: ";
    while(s.size()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
