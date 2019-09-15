#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int l, int r, int x) 
{ 
	if (r >= l) { 
		int mid = l + (r - l) / 2; 
		if (arr[mid] == x) 
			return mid; 
		if (arr[mid] < x) 
			return binarySearch(arr, l, mid - 1, x); 
		return binarySearch(arr, mid + 1, r, x); 
	} 
	else
		return (r+l)/2; 
} 


int main() {

	vector<int> v = {100,100,50,40,40,20,10};

	int l = 0, u = v.size()-1;
	int mid;

	//	cout << v[0] << endl << v[v.size()-1] << endl;

	int x;
	cin >> x;

	cout << binarySearch(v, 0, v.size()-1, x) << endl;

	// shit doesn't work

	//while(u >= l) {
	//	mid = (l + u) /2;
	//	if(v[mid] == x) {
	//		cout << mid << endl;
	//		break;
	//	}
	//	else if( v[mid] > x)
	//		u = mid - 1;
	//	else if(v[mid] < x)
	//		l = mid + 1;
	//}

	//if(u< l) {
	//	cout << mid << endl;
	//}


	return 0;
}
