#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &v, int x) {
    if(v.empty() || v.back() <= x) {
        v.push_back(x);
        return;
    }
    int temp = v.back();
    v.pop_back();
    insert(v, x);
    v.push_back(temp);
}

void sort(vector<int> &v) {
    if(v.size() == 1) {
        return;
    }
    int temp = v.back();
    v.pop_back();
    sort(v);
    insert(v, temp);
}

int main () {
    vector<int> a {5, 1, 0, 2, 3};
    cout << "Input array: ";
    for(int i : a)
        cout << i << ' ';
    cout << endl;
    sort(a);
    cout << "Sorted array: ";
    for(int i : a)
        cout << i << ' ';
    cout << endl;
    return 0;
}
