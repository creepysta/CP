/*
 *
 *
 * hackerearth.com - coding arena
2
4 3
2 2
2 3
4 1
2 3
2 1
2 2
2 3
 *
 */


#include<iostream>
using namespace std;

int main()
{
	int t, n , q, flag = 0;
	cin >> t;
	while(t--) {

		cin >> n >> q;
		int field[n+1][4];
		for(int i = 1; i<= n; i++) {
			for(int j = 1; j <= 3; j++) {
				field[i][j] = 0;
			}
		}
		int x,y;
		for(int i = 0; i < q; i++) {

			cin >> x >> y;
			field[x][y] = 1;

		}

////	cout << " " << 1 << 2 << 3 << endl;
////	for(int i = 1; i <= n; i++) {
////		cout << i;
////		for(int j = 1; j <= 3; j++) {
////			cout << field[i][j];
////		}
////		cout << endl;
////	}

		//traversing
		int i = 1;
		int j = 2;
		while(i <= n) {
			while(j <= 3) {

				if(field[i+1][j-1] != 1) {
					i = i + 1;
					j = j - 1;
				}
				else if(field[i+1][j] != 1) {
					i = i + 1;
				}
				else if(field[i+1][j+1] != 1) {
					i = i + 1;
					j = j + 1;
				}
				else {
					flag = 1;
					break;
				}
			}
			if (flag == 1) {
				cout << 1 << endl;
				break;
			}
			cout << endl << i << j << endl;
		}
		if(flag == 0) {
			cout << i << endl;
		}

	}


	return 0;
}
