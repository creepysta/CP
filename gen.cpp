#include <bits/stdc++.h>
using namespace std;

// aggressive cows
//int main(int argc, char * argv[]) {
	//mt19937 rng(atoi(argv[1]));
    //cout << 1 << endl;
	//int n = rng() % 30;
    //int c = rng() % n;
    //cout << n << ' ' << c << endl;
    //set<int> s;
    //for(int i = 0; i < n; i++) {
        //int now = rng() % 1000;
        //while(s.count(now)) {
            //now = rng() % 1000;
            //continue;
        //}
        //s.insert(now);
        //cout << now << ' ';
    //}
	//cout << endl;
	//return 0;
//}


/*
1
Comparing files out and OUT1
***** out
21
***** OUT1
25
*****
*/

//Subset sums


//int main(int argc, char * argv[]) {
	//mt19937 rng(atoi(argv[1]));
	//int n = 10 + rng() % (15 - 10) + 1;
    //int neg = rng() % 2;
    //int a = rng() % n;
    //int b = a + rng() % (n-a) + 1;
    //a = neg ? -a : a;
    //cout << n << ' ' << a << ' ' << b << endl;
    //for(int i = 0; i < n; i++) {
        //int now = rng() % 10;
        //neg = rng() % 70;
        //now = neg > 70 ? -now : now;
        //cout << now << ' ';
    //}
	//cout << endl;
	//return 0;
//}


//relevel oct-30
int main(int argc, char * argv[]) {
    mt19937 rng(atoi(argv[1]));
    cout << 1 << endl;
    int n = 1 + rng() % 100;
    int k = 1 + rng() % n;
    cout << n << endl << k << endl;
    return 0;
}
