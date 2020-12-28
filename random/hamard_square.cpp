#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void display(vector<vector<bool>> &a) {
	int row = a.size();
	int col = a[0].size();
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<vector<bool>> a = {{1,1},{1,0}};
	display(a);
	vector<vector<bool>> temp;
	for(int k = 2; k <= (int) log2(n); k++) {
		int row = a.size(), rows=0;
		int col = a[0].size(), cols = 0;
		int curr_size = pow(2, k);
		temp.clear();
		temp.resize(curr_size, vector<bool> (curr_size));
		int tr = 0, tc = 0;
		for(rows = 0; rows < 2; rows++) {
			for(int i = 0; i < row; i++) {
				for(cols = 0; cols < 2; cols ++) {
					for(int j = 0; j < col; j++) {
						if(rows == 1 && cols == 1)
						temp[tr][tc] = !a[i][j];
						else
						temp[tr][tc] = a[i][j];
						tc++;
					}
				}
				tc = 0;
				tr++;
			}
		}
		a.clear();
		a.assign(temp.begin(), temp.end());
		display(a);
	}
	//display(a);
	return 0;
}
