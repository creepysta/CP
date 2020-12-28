#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> a = {1,2,4,3,3,1}; // {1,2,4,4,5,1}
	int n = a.size();
	bool f = 0;
	int day = 0;
	for(int i = 0; i < n; i++) {
		if(i < n-1 && a[i] >= a[i+1]){
			f = 1;
			while(i < n-1 && a[i] >= a[i+1]){
				i++;
			}
		}
		if(i < n-1 && a[i] <= a[i+1]){
			f = 1;
			while(i < n-1 && a[i] <= a[i+1]){
				i++;
			}
		}
		if(f){
			f = 0;
			day +=1 ;
			i -= 1;
		}
	}
	cout << day;
}
