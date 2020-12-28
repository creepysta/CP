#include<bits/stdc++.h>
using namespace std;

class Test{
    int *r;
    public:
    Test() {
        r = new int(100);
    };
    int *& ref() {
        return r;
    }
    void show() {
        cout << *r;
    }
};

int main() {
    Test t;
    int r = 5;
    t.ref() = &r;
    t.show();
}
