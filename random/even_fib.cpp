// Even Fibonacci numbers
//projecteuler.net/problem=2

#include<bits/stdc++.h>
using namespace std;

int main()
{
    auto c = 0, final_sum = 0;
    const int limit = 400000;
    auto a = 0;
    auto b = 2;
    c = a + b;

    final_sum = c;
    while(true) {
        c = a + 4 * b;
        if (c > limit)
            break;
        final_sum = final_sum + c;
        a = b;
        b = c;

    }
    cout << final_sum << endl;

    return 0;
}
