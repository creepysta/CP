/*
https://www.hackerrank.com/challenges/interval-selection/problem?h_r=next-challenge&h_v=zen
*/
#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--) {
        int intervals, arr[100][2], count = 0, s, t;
        for (int i = 0; i < intervals; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> a[i][j];
            }
        }
        // sorting in respect to 's'
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100 - i - 1; j++) {
                if (arr[j][0] > arr[j+1][0]) {
                    swap(arr[j][0], arr[j+1][0]);
                    swap(arr[j][1], arr[j+1][1]);
                }
            }
        }
        
    }

    return 0;
}
