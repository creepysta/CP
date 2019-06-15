#include<iostream>
using namespace std;

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

main()
{
	int arr[][2] = {{1,10},{1,3},{4,6},{2,10}}, row =4, col =2;
	for(int i=0; i< row; i++) {
		for(int j = 0; j< row - i -1; j++) {
			if (arr[j][0] > arr[j+1][0]) {
				swap(&arr[j][0], &arr[j+1][0]);
				swap(&arr[j][1], &arr[j+1][1]);
				if(arr[j][1] < arr[j+1][1]) {
					swap(arr[j][0], arr[j+1][0]);
					swap(arr[j][1], arr[j+1][1]);
				}
			}
		}
	}
	for(int i = 0; i< row; i++) {
		for(int j = 0; j < col; j ++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
